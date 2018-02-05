#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout << nums[i]<<" ";
  }
  cout << endl;
}
void print2d(vector<vector<int>> res){
  for(int i=0;i<res.size();i++){
    print(res[i]);
  }
  cout << endl;
}

class Solution {
public:
    void bt(vector<int> nums, vector<vector<int>>& res, int n){
      if(n==nums.size())
        res.push_back(nums);
      for(int i=n;i<nums.size();i++){
        if(i!=n && nums[n]==nums[i]) continue;
        swap(nums[n], nums[i]);
        bt(nums, res, n+1);
      }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      bt(nums, res, 0);
      return res;
    }
};



int main(){
  Solution so;

  vector<int> nums{1,1,2};
  print2d(so.permuteUnique(nums));
  // [1,1,2],
  // [1,2,1],
  // [2,1,1]

  vector<int> nums2{3,3,0,3};
  print2d(so.permuteUnique(nums2));
  // [[0,3,3,3],
  // [3,0,3,3],
  // [3,3,0,3],
  // [3,3,3,0]]

 
}