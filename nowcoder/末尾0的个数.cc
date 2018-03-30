#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int foo(int n){
  int ans =0;
  for(int i=5;i<=n;i+=5){
    int t=i;
    while(t%5==0){
      ++ans;
      t/=5;
    }
  }
  return ans;
}

int main(){
  
  int n=100;
  cin >>n;
    
  printf("%d\n", foo(n));
  return 0;
}