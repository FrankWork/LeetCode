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
      // print(nums);
      if(n==nums.size())
        res.push_back(nums);
      for(int i=n;i<nums.size();i++){
        swap(nums[n], nums[i]);
        
        bt(nums, res, n+1);
        // swap(nums[n], nums[i]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      bt(nums, res, 0);
      return res;
    }
};



int main(){
  Solution so;

  vector<int> nums{1,2,3};
  print2d(so.permute(nums));
    // [1,2,3],
    // [1,3,2],
    // [2,1,3],
    // [2,3,1],
    // [3,1,2],
    // [3,2,1]

  vector<int> nums2{1,2,3,4};
  print2d(so.permute(nums2));

  // vector<int> nums3{5,4,6,2};
  // print2d(so.permute(nums3));
  // [[5,4,6,2],[5,4,2,6],[5,6,4,2],[5,6,2,4],[5,2,4,6],[5,2,6,4],
  // [4,5,6,2],[4,5,2,6],[4,6,5,2],[4,6,2,5],[4,2,5,6],[4,2,6,5],
  // [6,5,4,2],[6,5,2,4],[6,4,5,2],[6,4,2,5],[6,2,5,4],[6,2,4,5],
  // [2,5,4,6],[2,5,6,4],[2,4,5,6],[2,4,6,5],[2,6,5,4],[2,6,4,5]]
}