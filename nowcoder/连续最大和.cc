#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int max(int a, int b, int c){
  return max(max(a,b),c);
}
int main(){
  int n;
  cin >>n;
  vector<int> nums(n);
  for(int i=0;i<n;++i){
    cin>>nums[i];
  }

  vector<int> dp(n);
  dp[0]=nums[0];
  int tmp=nums[0];
  for(int i=1;i<nums.size();++i){
    if(tmp==dp[i-1]){
      dp[i]=max(nums[i], nums[i]+dp[i-1], dp[i-1]);
      tmp= max(nums[i], nums[i]+dp[i-1]);
    }else{
      dp[i]=max(nums[i], nums[i]+tmp, dp[i-1]);
      tmp=max(nums[i],nums[i]+tmp);
    }
  }
  
  cout <<dp[n-1]<<endl;
  
  return 0;
}