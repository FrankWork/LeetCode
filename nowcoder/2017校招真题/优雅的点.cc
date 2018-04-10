#include<iostream>
#include<vector>
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

int main(){
  int n2;
  cin>>n2;
  
  int sum=0, n=static_cast<int>(sqrt(n2));
  for(int i=1;i<=n;++i){
    for(int j=0;j<=n;++j){
      if(i*i+j*j==n2){
        printf("%d,%d\n",i,j);
        ++sum;
      }
        
    }
  }
  cout << 4*sum;
  
}
// 25 12
// 365 16