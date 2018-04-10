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
  int t, m=0;
  vector<int> nums(10000+1);
  for(int i=1;i<9998;++i){
    cin>>t;
    ++nums[t];
  }
  
  vector<int> ans;
  for(int i=1;i<10000+1;++i){
    if(!nums[i]){
      ans.push_back(i);
    }
  }

  int n=1;
  while(ans[1]>=n){
    n*=10;
  }

  ans[0]=ans[0]*n+ans[1];
  while(ans[2]>=n){
    n*=10;
  }
  ans[0]=ans[0]*n+ans[2];
  
  cout << ans[0]%7<<endl;
  
  return 0;
}