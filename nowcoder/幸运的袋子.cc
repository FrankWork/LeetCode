#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp;

void print(vector<int> & nums){
  for(int n:nums){
    cout << n << " ";

  }
  cout <<endl;
}

int dfs(vector<int>&nums, int start, int sum, int prod){
  int n=0;

  for(int i=start;i<nums.size();++i){
    if(i>start&&nums[i]==nums[i-1]){continue;}
    // temp.push_back(nums[i]);
    sum+=nums[i];
    prod*=nums[i];
    if(sum>prod){
      // print(temp);
      n+=1+dfs(nums, i+1, sum, prod);
    }else if(nums[i]==1){
      n+=dfs(nums, i+1, sum, prod);
    }
    sum-=nums[i];
    prod/=nums[i];
    // temp.pop_back();
  }
  return n;
}

int main(){
    int n;
    cin >>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    int sum=0, prod=1;
    cout << dfs(nums, 0, sum, prod) << endl;
    return 0;
}