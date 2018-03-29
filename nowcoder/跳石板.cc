#include<iostream>
#include<vector>
#include <cstdio>
#include <cmath>
#include <climits>
#include<queue>

using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

vector<int> getK(int x){
  vector<int> res;
  for(int i=2;(i*i)<=x;++i){
    if(x%i==0){
      res.push_back(i);
      res.push_back(x/i);
    }
  }
  return res;
}

int main(){
  int n,m;
  cin>>n>>m;
  // int n=8,m=85678;

  vector<int> steps(m+1, INT_MAX);
  steps[n]=0;
  for(int i=n;i<m+1;++i){
    if(steps[i]==INT_MAX)continue;
    vector<int> Ks=getK(i);
    for(int k:Ks){
      // cout <<k<<" ";
      if(i+k<m+1){
        steps[i+k]=min(steps[i+k], steps[i]+1);
      }
    }
    // cout <<endl;
  }
  // print(steps);
  if(steps[m]==INT_MAX)
    cout <<-1<<endl;
  else
    cout << steps[m]<<endl;
  return 0;
}
// 4 24 -> 5
// 8 85678 -> 31