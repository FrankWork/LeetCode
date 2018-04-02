#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
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


void rev(string& str, int l,int r){
  int m=(r-l+1)/2;
  for(int i=0;i<m;++i){
    swap(str[l+i], str[r-i]);
  }
}

int main(){
  string str;
  getline(cin, str);
  int n = str.length();
  
  int l=0, r=0;
  for(int i=0;i<n;++i){
    if(isspace(str[i])){
      rev(str, l, i-1);
      // cout << str<<endl;
      // cout<<str.substr(l,i-l)<<endl;
      l=i+1;
    }else if(i==n-1){
      rev(str, l, i);
    }
  }
  // cout << str<<endl;
  rev(str, 0, n-1);

  cout<<str<<endl;
  return 0;
}