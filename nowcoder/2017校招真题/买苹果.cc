#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int n,t;
  cin >>n;

  pair<int,int> x(0,0);
  queue<pair<int,int>> q;
  q.push(x);

  while(!q.empty()){
    x=q.front();q.pop();
    if(x.first==n){
      cout << x.second <<endl;
      return 0;
    }
    t=x.first+6;
    if(t<=n){
      pair<int,int> node(t, x.second+1);
      q.push(node);
    }
    t=x.first+8;
    if(t<=n){
      pair<int,int> node(t, x.second+1);
      q.push(node);
    }
  }
  
  cout << -1 <<endl;
  
  return 0;
}