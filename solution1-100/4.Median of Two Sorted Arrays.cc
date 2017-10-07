/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/
#include <iostream>
#include <vector>
using namespace std;
/**
[] [1] 1
[] [1,2] 1.5
[1] [1] 1
[1,1] [1,1] 1
[] [2,3] 2.5

*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int i=0,j=0;
      vector<int> nums;
      while(i< nums1.size() && j< nums2.size()){
        if(nums1[i] < nums2[j])
            nums.push_back(nums1[i++]);
        else
            nums.push_back(nums2[j++]);
      }
      while(i< nums1.size()){
        nums.push_back(nums1[i++]);
      }
      while(j< nums2.size()){
        nums.push_back(nums2[j++]);
      }
      int n = nums.size();
      int m = n/2;
      double ret;
      if(n%2==0){
         int sum= nums[m-1];
            sum += nums[m];
            ret = sum/2.0;
      }else{
            ret = nums[m];
      }
      return ret;
    }

};

int main(){
    vector<int> nums = {1,1};
    vector<int> nums2={1,2};
    Solution so;
    cout << so.findMedianSortedArrays(nums,nums2);
}
