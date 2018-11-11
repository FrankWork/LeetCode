#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <fstream>
#include <cstdio>
#include <cstring>

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

	char newline[]="\n";
	string line;
	int nLines=0;

	while(getline(fin, line)){
		nLines++;
		//fout << line << "\n";
		fout.write(line.c_str(), sizeof(char)*line.size());
		fout.write(newline, strlen(newline));
	}
	printf("nLines %d\n", nLines);
}

int main(){
	//string finName="wiki2.txt";
	string finName="wiki103.txt";
	string foutName="wiki.copy";

	//countLines(finName);
	//countWords(finName);
	//countLinesWords(finName);
	copyLines(finName, foutName);

		// values.push_back(42);

		// thread tr1(threadFnc, 1);
		// thread tr2(threadFnc, 2);
		// thread tr3(threadFnc, 3);
		// thread tr4(threadFnc, 4);

		// tr1.join();
		// tr2.join();
		// tr3.join();
		// tr4.join();
		// 
		// for(int v: values){
		//		 cout << v << " ";
		// }
		// cout << endl;
		return 0;
}
