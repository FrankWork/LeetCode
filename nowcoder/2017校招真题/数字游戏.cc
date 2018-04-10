#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void print(vector<int> & nums){
  for(int n:nums){
    cout << n << " ";

  }
  cout <<endl;
}

void dfs(vector<int>& nums, int start, int sum, unordered_set<int>& res){

  for(int i=start;i<nums.size();++i){
    if(i>start&&nums[i]==nums[i-1]){continue;}
    sum+=nums[i];
    res.insert(sum);
    dfs(nums, i+1, sum, res);
    sum-=nums[i];
  }
}

int main(){
    int n;
    cin >>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    unordered_set<int> res;
    dfs(nums, 0, 0, res);
    for(int i=1;i<res.size()+2;++i){
      if(res.find(i)==res.end()){
        cout << i << endl;
        break;
      }
    }
    // vector<int> tmp(res.begin(), res.end());
    // sort(tmp.begin(), tmp.end());
    // auto it=tmp.begin();
    // for(;it!=tmp.end();++it){
    //   cout << *it << " ";
    // }
    // cout << endl;
    return 0;
}