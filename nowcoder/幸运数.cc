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

int digits(int n){
  int m=0;
  while(n){
    m+=n%10;
    n/=10;
  }
  return m;
}

int main(){
  int n;
  while(cin>>n){
    int f,g, m=0;
    for(int i=1;i<=n;++i){
      f=digits(i);
      g=base(i, 2);
      if(f==g){
        ++m;
      }
    }
    
    printf("%d\n", m);
  }
  
  return 0;
}