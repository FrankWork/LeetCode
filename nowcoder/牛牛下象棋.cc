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

long long sum=0;
void dfs(vector<vector<int>>&used, int k, int x,int y, int r, int c){
  if(k<0 || r<0|| r>=10||c<0||c>=10 || used[r][c]==1)return;

  if(r==x && c==y){
    ++sum;
    return;
  }
  used[r][c]=1;
  // printf("%d %d\n", r, c);
  dfs(used, k-1, x,y,r+2,c+1);
  dfs(used, k-1, x,y,r+2,c-1);
  dfs(used, k-1, x,y,r-2,c+1);
  dfs(used, k-1, x,y,r-2,c-1);

  dfs(used, k-1, x,y, r+1,c+2);
  dfs(used, k-1, x,y, r-1,c+2);
  dfs(used, k-1, x,y, r+1,c-2);
  dfs(used, k-1, x,y, r-1,c-2);
  used[r][c]=0;
}
int main(){
  int k,x,y;
  cin>>k>>x>>y;
  vector<vector<int>> used(10, vector<int>(10));
  dfs(used, k, x, y, 0, 0);
  cout <<sum<<endl;


  
  return 0;
}