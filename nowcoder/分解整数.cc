#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
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

vector<long long> foo(long long m){
  long long k=0,i,t;
  vector<long long> a;
  for(i=1;i*i<m;++i){
    if(m%i==0){
      t=m/i;
      if(i%2==0 && t%2!=0){
        a.push_back(i);
      }
      if(t%2==0 && i%2!=0){
        a.push_back(t);
      }
    }
  }
  // if(i*i==m){
  //   if(i%2==0)
  //     a.push_back(i);
  // }
  return a;
}


int main(){
  int t;
  cin>>t;
  for(int ii=0;ii<t;++ii){
    long long n;
    cin>>n;
    auto a=foo(n);
    
    if(a.size()>0){
      sort(a.begin(), a.end());
      cout << n/a[0] << " "<<a[0]<<endl;
    }else{
      cout << "No"<<endl;
    }
  }
  
  
  return 0;
}