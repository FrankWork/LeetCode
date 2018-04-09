#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << ",";
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

struct Price{
  int begin;
  int end;
  int price;
  Price(){}
  Price(int b,int e, int p):begin(b),end(e),price(p){}
  bool operator<(const Price &o){
    return begin<o.begin;
  }
};

ostream& operator<<(ostream& os, const Price&p){
  os << '[' << p.begin<<", "<<p.end <<", "<<p.price<<']';
  return os;  
}

void print_map(const map<int,pair<int,int>> &s){
  for(auto it=s.begin();it!=s.end();++it){
    printf("[%d, %d, %d]\n", it->first, it->second.first, it->second.second);
  }
}

int a[10000];

int main(){
  int b,e,p;
  memset(a, 0, 10000*sizeof(int));
  int m=0;
  while(cin>>b>>e>>p){
    for(int i=b;i<=e;++i){
      a[i]=p;
      m=max(m, e);
    }
  }
  vector<Price> vec;
  for(int i=0;i<=m;++i){
    while(a[i]==0){
      ++i;
    }
    if(a[i-1]==0 || a[i]!=a[i-1]){
      b=i;
    }
    if(a[i+1]!=a[i]){
      e=i;
      Price p(b,e,a[i]);
      vec.push_back(p);
    }
  }
  print(vec);
  
  return 0;
}