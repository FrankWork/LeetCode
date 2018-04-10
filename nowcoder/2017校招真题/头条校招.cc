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


int main(){
  int n;
  cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;++i){
    cin>>d[i];
  }
  int ans=0;
  while(n%3!=0){
    ++ans;
    ++n;
  }
  cout << ans<<endl;
  return 0;
}