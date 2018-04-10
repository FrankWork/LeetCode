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
  int m;
  double n;
  while(cin>>n>>m){
    double ans=0;

    for(int i=0;i<m;++i){
      ans += n;
      n=sqrt(n);
    }
    printf("%.2f\n", ans);
  }
  
  
  return 0;
}