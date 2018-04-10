#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <cmath>
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
  int n, m;
  while(cin>>n>>m){
    set<int> a;
    int t;
    for(int i=0;i<n;++i){
      cin>>t;
      a.insert(t);
    }
    for(int i=0;i<m;++i){
      cin>>t;
      a.insert(t);
    }
    vector<int> ans(a.begin(), a.end());
    print(ans);
  }
  
  
  return 0;
}