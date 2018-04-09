#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<string>
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
  set<char> chars{'A','B','C','D','E'};
  while(cin>>str){
    
  }
  
  return 0;
}