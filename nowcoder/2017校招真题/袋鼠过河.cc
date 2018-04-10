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
  int n;
  cin>>n;
  vector<int> nums(n), dp(n+1);
  // dp[0]=;
  for(int i=0;i<n;++i){
    cin>>nums[i];
    if(dp[i]==0 && nums[i]==0)
      break;
    for(int j=1;j<=nums[i] && i+j<n+1;++j){
      if(dp[i+j]==0)dp[i+j]=dp[i]+1;
      else dp[i+j]=min(dp[i+j], dp[i]+1);
    }
  }
  // print(dp);
  cout << (dp[n]==0?-1:dp[n])<<endl;

  return 0;
}