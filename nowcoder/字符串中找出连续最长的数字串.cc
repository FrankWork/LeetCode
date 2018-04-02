#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
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
  string str;
  cin>>str;
  vector<int> dp(str.length());
  dp[0]= isdigit(str[0]) ? 1 : 0;
  int maxLen=0;
  for(int i=1;i<dp.size();++i){
    if(isdigit(str[i]) && str[i]==str[i-1]+1){
      dp[i] = dp[i-1]+1;
      maxLen = max(maxLen, dp[i]);
    }
    else
      dp[i]=0;
  }
  for(int i=0;i<dp.size();++i){
    if(dp[i]==maxLen){
      cout << str.substr(i-maxLen, maxLen+1)<<endl;
    }
  }
  // print(dp);
  // cout << maxLen<<endl;
  
  
  return 0;
}