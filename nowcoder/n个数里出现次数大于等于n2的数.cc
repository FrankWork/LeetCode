#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
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
  vector<int> nums;
  int t;
  while(cin>>t){
    nums.push_back(t);
  } 
  // print(nums);
  int n=nums.size();
  map<int, int> count;
  for(int i=0;i<n;++i){
    ++count[nums[i]];
  }
  vector<vector<int>> freq(n, vector<int>());
  for(auto it:count){
    freq[it.second].push_back(it.first);
  }
  vector<int> ans;
  for(int i=n/2;i<n;++i){
    for(int j=0;j<freq[i].size();++j){
      ans.push_back(freq[i][j]);
    }
  }
  print(ans);
  return 0;
}