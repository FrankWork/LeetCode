#include "../template.h"


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* 众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素

        先对数组排序，最中间那个数出现次数一定多于 n / 2。
        或利用 Boyer-Moore Majority Vote Algorithm 
        */
       sort(nums.begin(), nums.end());
       return nums[nums.size()/2];
    }
};