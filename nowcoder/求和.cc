#include <iostream>
#include <vector>
#include <cstdio>
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

void dfs(vector<int> &nums, vector<vector<int>>&res, vector<int> tmp, int idx, int n, int m){
  for(int i=idx;i<=n;++i){
    
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> nums(n+1);
  for(int i=1;i<=n;++i){
    nums[i]=i;
  }

  vector<vector<int>> res;
  vector<int> tmp;
  dfs(nums, res, tmp, 1, n, m);
  
  return 0;
}