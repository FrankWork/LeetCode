#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <unordered_set>
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

vector<int> getPrimes(int n){
  vector<int> p(n+1, 1);
  vector<int> ans;
  p[0]=p[1]=0;
  for(int i=2;i<=n;++i){
    for(int j=2;p[i] && j<=sqrt(i);++j){
      if(i%j==0){
        for(int k=1;k*i<=n;++k){
          p[k*i]=0;
        }
        break;
      }
    }
    if(p[i])
      ans.push_back(i);
  }
  return ans;
}

int main(){
  int n;
  cin>>n;

  auto p=getPrimes(n);
  // for(int i:p){
  //   printf("%d ", i);
  // }
  // cout<<endl;
  unordered_set<int> s;
  for(int i=0;i<p.size();++i){
    int t=n-p[i];
    if(t>0){
      s.insert(t);
    }
  }
  int ans=0;
  for(int i=0;i<p.size() && p[i]<=n/2;++i){
    if(s.find(p[i])!=s.end()){
      ans++;
      // cout<<p[i]<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
}