#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<string>
#include <bitset>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
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


bool valid(const string &str, int l, int r){
  bitset<8> s;
  int t;
  for(int i=l;i<=r;++i){
    t=str[i]-'A';
    if(t<5)
      s.set(t);
  }
  return s.count()==5;
}

int main(){
  string str;
  
  while(cin>>str){
    int l=0,r=0,n,step=0, ans;
    str+=str;
    n=str.length();
    ans=n;
    while(l<=r && r<n && l<n){
      if(valid(str, l, r)){
        ans =min(ans, r-l+1);
        if(ans==5)break;
        ++l;
      }else{
        ++r;
      }
    }
    cout << n/2-ans<<endl;
  }
  
  return 0;
}