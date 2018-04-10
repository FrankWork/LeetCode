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

void dfs(vector<int> &nums, vector<vector<int>>&res, 
         vector<int> &tmp, int idx, int sum, int n, int m){
  if(sum==m){
    res.push_back(tmp);
    return;
  }else if(sum>m){
    return;
  }

  for(int i=idx;i<=n;++i){
    sum+=nums[i];
    tmp.push_back(nums[i]);
    dfs(nums, res, tmp, i+1, sum, n,m);
    tmp.pop_back();
    sum-=nums[i];
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> nums(n+1);
  for(int i=1;i<=n;++i){
    nums[i]=i;
  }
  // print(nums);

  vector<vector<int>> res;
  vector<int> tmp;
  dfs(nums, res, tmp, 1, 0, n, m);
  for(int i=0;i<res.size();++i){
    print(res[i]);
  }
  return 0;
}