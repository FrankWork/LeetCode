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
  int flag=0;
  while(cin>>n){
    vector<vector<int>> nums(n, vector<int>(n));
    int a=0,b=0,c=n-1, d=n-1;
    int val=1;
    while(a<=c && b<=d){
      for(int y=b;y<=d;++y)nums[a][y]=val++;
      for(int x=a+1;x<n && x<=c;++x)nums[x][d]=val++;
      for(int y=d-1;y>=0 && y>=b;--y)nums[c][y]=val++;
      for(int x=c-1;x>=0 && x>a;--x)nums[x][b]=val++;
      ++a;++b;
      --c;--d;
    }
    if(!flag){
      flag = 1;
    }else{
      cout << endl;
    }
    print2d(nums);
  }
  
  return 0;
}