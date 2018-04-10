#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

template<class T>
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
  
  vector<vector<long long>> dp(target+1, vector<long long>(n));

  vector<int> nums(n);
  for(int i=0;i<n;++i){
    cin>>nums[i];
  }
  
  
  dp[nums[0]][0]=1;
  long long t;
  for(int j=1;j<n;++j){
    for(int i=1;i<=target;++i){
      // if(dp[i][j-1]==0)continue;
      t = i-nums[j];
      if(i==nums[j])
        dp[i][j] = 1+dp[i][j-1];
      else if(t>0&& t<=target)
        dp[i][j] = dp[i][j-1]+dp[t][j-1];
      else dp[i][j]=dp[i][j-1];
    }
  }
  print2d(dp);
  cout << dp[target][n-1]<<endl;
  
  return 0;
}