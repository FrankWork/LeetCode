#include<iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int dfs(int len, int n, vector<char>& chars, vector<char>&cache){
  int sum=0;
  if(len==n){
    for(char c:cache)
     cout<<c<<" ";
     cout <<endl;
    return 1;
  }
  int m=cache.size();
  for(int i=0;i<3;++i){
    if(m>=2 && chars[i]!=cache[m-1] && chars[i]!=cache[m-2] && cache[m-1]!=cache[m-2]){
      continue;
    }
    cache.push_back(chars[i]);
    sum+=dfs(len+1, n, chars, cache);
    cache.pop_back();
  }
  return sum;
}

int main(){
  int n;
  vector<char> chars{'A','B','C'};
  
  while(cin>>n){
    // vector<char> cache;
    // cout << dfs(0, n, chars, cache) <<endl;
    vector<long long> aa{3, 3};
    vector<long long> ab{0, 6};
    for(int i=2;i<n;++i){
      aa.push_back(aa[i-1]+ab[i-1]);
      ab.push_back(2*aa[i-1]+ab[i-1]);
    }
    cout << aa[n-1]+ab[n-1]<<endl;
  }
  return 0;
}