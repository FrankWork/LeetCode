#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int n;
  cin >>n;
  
  long ans=0, t;
  for(int i=n;i>0;i/=2){
    t = (i+1)/2;
    ans += t*t;
  }
  
  
  cout << ans <<endl;
  
  return 0;
}