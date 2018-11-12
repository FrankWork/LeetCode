#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
mutex
thread
thread_local mt19937 generator
uniform_int_distribution
*/

mutex values_mtx;
mutex cout_mtx;
vector<int> values;

int randGen(const int& min, const int&max){
		static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id()));
		uniform_int_distribution<int> distribution(min, max);
		return distribution(generator);
}

void threadFnc(int tid){
		cout_mtx.lock();
		cout << "thread "<<tid<<".\n";
		cout_mtx.unlock();

		values_mtx.lock();
		int val = values[0];
		values_mtx.unlock();

		int rval = randGen(0, 10);
		val += rval;

		cout_mtx.lock();
		cout << "thread "<<tid<<" adding "<<rval<<".\n";
		cout_mtx.unlock();

		values_mtx.lock();
		values.push_back(val);
		values_mtx.unlock();

}

// fastText	dictinoary.cc
bool readWord(std::istream& in, std::string& word) 
{
	int c;
	std::streambuf& sb = *in.rdbuf();
	word.clear();
	while ((c = sb.sbumpc()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' ||
				c == '\f' || c == '\0') {
			if (word.empty()) {
				if (c == '\n') {
					// word += EOS; // EOS = "</s>";
					return true;
				}	 
				continue;
			} else {
				if (c == '\n')
					sb.sungetc();
				return true;
			}	 
		}	 
		word.push_back(c);
	}
	// trigger eofbit
	in.get();
	return !word.empty();
}

void countWords(string& finName){
	ifstream fin(finName);
	string buf;
	int nWords = 0;

	while(readWord(fin, buf)){
		nWords++;
	}
	printf("nWords %d\n", nWords);
}

void countLines(string& finName){
	ifstream fin(finName);
	string buf;
	int nLines=0;

	while(getline(fin, buf)){
		nLines++;
	}
	printf("nLines %d\n", nLines);
}

void countLinesWords(string& finName){
	ifstream fin(finName);
	//string buf;
	int nLines=0, nWords=0;
	
	int c;
	std::streambuf& sb = *fin.rdbuf();
	//word.clear();
	while ((c = sb.sbumpc()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' ||
				c == '\f' || c == '\0') {
			nWords++;
			if(c=='\n'){
				nLines++;
			}
		}	 
		//word.push_back(c);
	}
	// trigger eofbit
	fin.get();
	printf("nLines %d, nWords %d\n", nLines, nWords);
}

void copyLines(string& finName, string& foutName){
	ifstream fin(finName);
	ofstream fout(foutName);

	char eol[]="\n"; // End of Line
	string line;
	int nLines=0;

	while(getline(fin, line)){
		nLines++;
		//fout << line << "\n";
		fout.write(line.c_str(), sizeof(char)*line.size());
		fout.write(eol, strlen(eol));
	}
	printf("nLines %d\n", nLines);
}

class CopyTask{
public:
	CopyTask(const string& finName, const string& foutName, int nThreads)
		: nThreads_(nThreads){
		fin.open(finName);
		fout.open(foutName);
		strcpy(eol, "\n");
	}
	void run(){
		if(nThreads_ <= 1){// 单线程
			while(getline(fin, line_)){
				nLines++;
				fout.write(line_.c_str(), sizeof(char)*line_.size());
				fout.write(eol, strlen(eol));
			}
		}else{// 多线程
			for(int i=0;i<nThreads_;++i){
				thread tr(&CopyTask::copyThreadFunc, this);
				tr.join();
			}
		}
		printf("nLines %d\n", nLines);
	}
	void copyThreadFunc(){
		// 能不能保证拷贝的顺序和原来的相同?
		// 试验了一次顺序是相同的
		string line;
		bool ok;

		while(true){
			rd_mtx.lock();
			ok = getline(fin, line);
			rd_mtx.unlock();

			if(!ok) break;

			ct_mtx.lock();
			nLines++;
			ct_mtx.unlock();

			wt_mtx.lock();
			fout.write(line.c_str(), sizeof(char)*line.size());
			fout.write(eol, strlen(eol));
			wt_mtx.unlock();
		}
	}
	~CopyTask(){
		fin.close();
		fout.close();
	}
private:
	mutex rd_mtx;
	mutex wt_mtx;
	mutex ct_mtx;

	ifstream fin;
	ofstream fout;

	char eol[2]; // End of Line
	string line_;
	int nLines=0;
	int nThreads_;
};



int main(int argc, char* argv[]){
	//string finName="wiki2.txt";
	string finName="wiki103.txt";
	string foutName="wiki.copy";

	//countLines(finName);
	//countWords(finName);
	//countLinesWords(finName);
	//copyLines(finName, foutName);
	int nThreads = 0;
	if(argc>1)
		nThreads = strtol(argv[1], NULL, 10);

	CopyTask task(finName, foutName, nThreads);
	task.run();

	return 0;
}
