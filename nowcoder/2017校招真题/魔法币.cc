#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void foo(int n){
  string res;

  while(n!=0){
    // cout << n << endl;
    if(n%2==0){
      res='2'+res;
      n = (n-2)/2;
    }else{
      res='1'+res;
      n = (n-1)/2;
    }
  }
  cout << res;
    
}

int main(){
    int n;
    cin >> n;
    // cout << n << endl;
    foo(n);
    //cout << res << endl;
    return 0;
}