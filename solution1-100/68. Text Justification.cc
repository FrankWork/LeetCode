#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
void print(const vector<T>& vec){
    for(T i: vec){
      cout << i << "x\n";
    }
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> cache;
        vector<int> nchar;
        int line=0;
        cache.push_back(vector<string>());
        nchar.push_back(0);


        for(int i=0;i<words.size();++i){
          int length = words[i].length() + (nchar[line]==0? 0:1);
          if(nchar[line] + length <= maxWidth){
            if(!nchar[line]==0){
              cache[line].push_back(" "+words[i]);
            }else{
              cache[line].push_back(words[i]);
            }
            nchar[line]+=length;
          }else{
            vector<string> tmp;
            tmp.push_back(words[i]);
            cache.push_back(tmp);
            nchar.push_back(words[i].length());
            ++line;
          }
        }
        // for(int i=0;i<=line;++i){
        //   for(int j=0;j<cache[i].size();j++)
        //     cout << cache[i][j];
        //   cout << '\n';
        // }

        vector<string> res;
        int j;
        for(int i=0;i<line;++i){
          j=0;
          while(nchar[i]<maxWidth){
            cache[i][j]+=" ";
            ++nchar[i];
            ++j;
            if(j>=(cache[i].size()-1)){
              j=0;
            }
          }
        }
        if(nchar[line]<maxWidth){
          cache[line].push_back(string(maxWidth-nchar[line], ' '));
        }

        for(int i=0;i<=line;++i){
          res.push_back("");
          for(j=0;j<cache[i].size();++j){
            res[i]+=cache[i][j];
          }
        }

        return res;
    }
};

int main(){
  Solution so;
  // vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
  // vector<string> res = so.fullJustify(words, 16);

  //  "This    is    an",
  //  "example  of text",
  //  "justification.  "

  // vector<string> words{"a","b","c","d","e"};
  // vector<string> res = so.fullJustify(words, 3);
    // "a b",
    // "c d",
    // "e  "

  vector<string> words{"What","must","be","shall","be."};
  vector<string> res = so.fullJustify(words, 12);

  print(res);
}