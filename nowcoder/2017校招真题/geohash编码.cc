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

void bs(int n, int level, int l, int r){
  
  if(level<6){
    int m=(l+r)/2;
    // printf("%d %d %d %d %d\n", level, l, m, r, n<m?0:1);
    if(n<m){
      cout<<0;
      bs(n,level+1, l, m);
    }
    else {
      cout<<1;
      bs(n, level+1,m,r);
    }
    
  }
}

int main(){
  int n;
  cin>>n;
  bs(n, 0, -90, 90);
  cout <<endl;
  return 0;
}