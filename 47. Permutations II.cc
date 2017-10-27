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
        swap(nums[n], nums[i]);
        
        bt(nums, res, n+1);
      }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> res;
      bt(nums, res, 0);
      return res;
    }
};



int main(){
  Solution so;

  vector<int> nums{1,1,2};
  print2d(so.permuteUnique(nums));
    // [1,2,3],
    // [1,3,2],
    // [2,1,3],
    // [2,3,1],
    // [3,1,2],
    // [3,2,1]

  // vector<int> nums2{1,2,3,4};
  // print2d(so.permuteUnique(nums2));

 
}