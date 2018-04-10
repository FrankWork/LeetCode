#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

void print2d(vector<vector<int>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}


int main(){
  string path;
  while(cin>>path){
    int i = path.rfind('/');
    if(i!=-1){
      path=path.substr(i+1, path.length()-i-1);
    }
    i=path.rfind('.');
    string ans="null";
    if(i!=-1){
      ans=path.substr(i+1, path.length()-i-1);
    }
    cout <<ans<<endl;
  }
  return 0;
}