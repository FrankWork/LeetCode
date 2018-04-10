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

int base(int n, int b){
  int ans=0;
  while(n>0){
    ans+=n%b;
    n/=b;
  }
  return ans;
}

int gcd(int sum, int m){
  int r;
  while((r=sum%m)!=0){
    sum=m;
    m=r;
  }
  return m;
}

int main(){
  int n;
  while(cin>>n){
    int sum=0, m=0;
    for(int i=2;i<n;++i){
      // cout << base(n, i)<<endl;
      sum += base(n,i);
      ++m;
    }
    int r=gcd(sum, m);
    printf("%d/%d\n", sum/r, m/r);
  }
  
  return 0;
}