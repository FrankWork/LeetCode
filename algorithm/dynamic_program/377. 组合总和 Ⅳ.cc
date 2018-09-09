#include "../template.h"



class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /* 完全背包问题，
          dp(i) 组成i的个数

          3 = 1+2,
          dp(3) = dp(2)+dp(1)

          dp(i) = sum( dp(i-j) ), j in nums
        */
       int n=nums.size();
       vector<int> dp(target+1);
       dp[0]=1;

       for(int i=1;i<=target;i++){
         for(int j: nums){
           if(i-j>=0)
            dp[i] += dp[i-j];
         }
         
       }
       return dp[target];
    }
};