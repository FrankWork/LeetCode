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

int dfs(vector<int>&nums, int start, int sum, int target){
  int ans=0;
  if(sum==target){
    return 1;
  }
  for(int i=start;i<nums.size();++i){
    sum+=nums[i];
    if(sum<=target){
      ans+=dfs(nums, i+1, sum, target);
    }
    
    sum-=nums[i];
  }
  return ans;
}

int main(){
  int n,target;
  cin>>n>>target;
  vector<int> nums(n);
  for(int i=0;i<n;++i){
    cin>>nums[i];
  }
  
  vector<vector<int>> dp(n, vector<int>(target));
  dp[0][0]=1;
  dp[0][nums[0]]=1;
  for(int i=0;i<target;++i){
  
  }
  dp[n]
  cout << dfs(nums, 0, 0, target) <<endl;
  
  return 0;
}