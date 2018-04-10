#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
  string str;
  while(getline(cin, str)){
    int j=0;
    for(int i=0;i<str.length();++i){
      if(str[i]==' '){continue;}
      cout << str[i];
      ++j;
      if(j==6||j==6+8){
        cout <<" ";
      }
    }
    cout <<endl;
  }
  
  return 0;
}