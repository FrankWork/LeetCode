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

bool valid(const string& a){
    int n=a.length();
    for(int i=0;i<n/2;++i){
        if(a[i]!=a[n-i-1]){
            return false;
        }
    }
    return true;
}
int sum=0;
void dfs(string&str, string &tmp, int idx){
  if(idx==str.length())
    return ;
  for(int i=idx;i<str.length();++i){
    tmp.push_back(str[i]);
    if(valid(tmp)){
      cout <<tmp<<endl;
      ++sum;
    }
    dfs(str, tmp, i+1);
    tmp.pop_back();
  }
}

int main(){
  string str;
  cin>>str;
  string tmp;
  dfs(str, tmp, 0);
  cout << sum<<endl;
  return 0;
}