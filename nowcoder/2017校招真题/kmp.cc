#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int brute(const string& text, const string& pattern){
  bool find=true;

  for(int i=0;i<text.length();++i){
    find=true;
    for(int j=0;j<pattern.length();++j){
      if(text[i+j]!=pattern[j]){
        find=false;
        break;
      }
    }
    if(find){return i;}
  }
  return -1;
}

vector<int> getNext(const string& pat){
  int n=pat.length();
  vector<int> next(n);
  next[0]=0;
  int j=0;
  for(int i=1;i<n;++i){
    while(j>0 && pat[i]!=pat[j]){
      j=next[j-1];
    }
    if(pat[i]==pat[j]){
      ++j;
    }
    next[i]=j;
  }
  return next;
}
int kmp(const string& text, const string& pat){
  int m = text.length(), n = pat.length();

  vector<int> next = getNext(pat);
  // for(int i:next){
  //   cout << i << " "; 
  // }
  // cout << endl;  

  int j=0;
  for(int i=0;i<m;++i){
    // printf("i:%d j:%d\n", i,j);
    while(j> 0 && text[i]!=pat[j]){
      j=next[j-1];
    }

    if(text[i]==pat[j]){
      ++j;
    }
    if(j==n){
      return i-j+1;
    }
  }
  return -1;
}


int main(){
  cout << kmp("BBC ABCDAB ABCDABCDABDE", "ABCDABD") << endl; // 15
  cout << kmp("ab", "a") << endl; // 0
  // for(int val: getNext("ababaca")){
  //   printf("%d ", val); // 0 0 1 2 3 0 1
  // }
  // cout << endl;
}