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

int sum=0;
int dfs(vector<vector<int>>& path, vector<vector<int>> &used,
int x,int y,int r, int c){
  if(r==x-1 && c==y-1){
    ++sum;
    return 0;
  }
  // int sum=0;
  
  if(r+1<x && used[r+1][c]==0){
    used[r][c]=1;
    dfs(path, used, x,y,r+1,c);
    used[r][c]=0;
  }
  if(c+1<y && used[r][c+1]==0){
    used[r][c]=1;
    dfs(path, used, x,y,r,c+1);
    used[r][c]=0;
  }
  
}

int main(){
  int x,y;
  cin>>x>>y;
  ++x;++y;
  vector<vector<int>> path(x, vector<int>(y));
  vector<vector<int>> used(x, vector<int>(y));
  dfs(path, used, x,y,0,0);
  cout << sum << endl;
  
  return 0;
}