#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

int main(){
  int n,m;
  cin >>n>>m;
  vector<int> a(n);
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  // print(a);

  // vector<int> b(m),c(m);
  // for(int i=0;i<m;++i){
  //   cin>>b[i]>>c[i];
  // }
  int b,c;
  map<int, vector<int>> bmap;
  for(int i=0;i<m;++i){
    cin>>b>>c;
    bmap[b].push_back(c);
  }
  vector<int> bvec;
  for(auto it:bmap){
    bvec.push_back(it.first);
    sort(it.second.begin(), it.second.end());
  }
  sort(bvec.begin(), bvec.end());
  sort(a.begin(), a.end());

  int ans=0,j=bvec.size()-1;
  for(int i=a.size()-1;i>=0;--i){
    while(bvec[j]>a[i] || bmap[bvec[j]].empty()){
      --j;
    }
    b = bvec[j];
    ans+=bmap[b].back();
    bmap[b].pop_back();

  }
  // print(b);
  // print(c);
  cout << ans <<endl;
  return 0;
}