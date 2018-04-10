#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
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

bool cmp(string&a, string&b){
  int an=a.length(),bn=b.length();
  int n=min(an,bn);
  for(int i=0;i<n;++i){
    if(a[i]==b[i])continue;
    return a[i]>b[i];
  }
  if(an>bn){
    for(int i=n;i<an;++i){
      if(a[i]==b[0])continue;
      return a[i]>b[0];
    }
  }
  for(int i=n;i<bn;++i){
      if(a[0]==b[i])continue;
      return a[0]>b[i];
  }

}

int main(){
  int n;
  while(cin>>n){
    vector<string> vec(n);
    for(int i=0;i<n;++i){
      cin>>vec[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0;i<vec.size();++i){
      cout <<vec[i];
    }
    cout<<endl;
  }
  // vector<string> vec{"936", "93", "12", "123"};//{"496","490","4"};
  // sort(vec.begin(), vec.end(), cmp);
  //   for(int i=0;i<vec.size();++i){
  //     cout <<vec[i]<<endl;
  //   }
  //   cout<<endl;
  // string a="12",b="936";
  // cout << cmp(a,b)<<endl;
  
 
  return 0;
}