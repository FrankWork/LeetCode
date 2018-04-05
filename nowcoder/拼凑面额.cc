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

int dfs(vector<int>&a, int idx, int sum, int n){
  if(sum==n){
    return 1;
  }else if(sum>n){
    return 0;
  }
  int ans=0;
  for(int i=idx;i<a.size();++i){
    sum+=a[i];
    if(sum<=n)
      ans+=dfs(a, i, sum, n);
    sum-=a[i];
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  vector<int> a{1,5,10,20,50,100};
  vector<long> dp(n+1);
  dp[0]=1;
  for(int j=0;j<6;++j){
    for(int i=1;i<=n;++i){
      if(i-a[j]>=0){
        dp[i]+=dp[i-a[j]];
      }
    }
    // print(dp);
  }
  
  cout << dp[n] <<endl;
  // print(dp);
  return 0;
}