#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include<cstring>
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
  int id1, id2;
  cin>>id1>>id2;
  if(id1<1||id1>1024||id2<1||id2>1024){
    cout << -1<<endl;
    return 0;
  }
  unsigned bitset[32];
  memset(bitset, 0, 32);
  
  bitset[id1/32] = (id1%32) | ;

  if(id2==id1){
    cout << 1<<endl;
  }
  else{
    cout << 0<<endl;
  }
  
  return 0;
}