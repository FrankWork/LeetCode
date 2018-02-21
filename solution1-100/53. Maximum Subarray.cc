#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
      /* max sub array is nums[i:j]
         a = sum(nums[i:j])
         b = sum(nums[i:n])
      */
      int a, b;
      a = b = nums[0];
      for(int i=1;i<nums.size();++i){
        int t = nums[i] + b;
        b = max(t, nums[i]);
        if(a<b){a=b;}
      }
      return a;
    }
};

int main(){
  Solution so;
  vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  int res = so.maxSubArray(nums);
  cout << res << " ";//6
  vector<int> nums1{-1, -2};
  res = so.maxSubArray(nums1);
  cout << res << " ";//-1
  vector<int> nums2{8, -19, 5, -4, 20};
  res = so.maxSubArray(nums2);
  cout << res << " ";//21
  return 0;
}

