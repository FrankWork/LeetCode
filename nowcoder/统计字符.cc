#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

template<class T>
void print2d(vector<vector<T>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}

int main(){
  string text;
  while(getline(cin, text)){
    map<char,int> s;
    for(char c:text){
      if(isalnum(c)){
        ++s[c];
        if(s[c]==3){
          cout <<c<<endl;
          break;
        }
      }
    }
  }
  
  return 0;
}