#include "../template.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        /* 递归法
           动态规划法
                dp(i, j) 表示前i个数字和为j的总数， j可能为负数， 用哈希表
                dp(i, j) = dp(i-1, j-a[i]) + dp(i-1, j+a[i])
        */
      //  int res=0;
      //  recursive(nums, S, res, 0, 0);
      //  return res;

      int n=nums.size();
      vector<unordered_map<int,int>> dp(n+1);

      dp[0][0] = 1;
      for(int i=1;i<=n;++i){
        int t = nums[i-1];
        for(auto x: dp[i-1]){
          int j=x.first, cnt=x.second;
          dp[i][j+t] += cnt;
          dp[i][j-t] += cnt;
        }
      }
      return dp[n][S];
    }

    void recursive(vector<int>& nums, int S, int &res, int idx, int sum){
      if(idx==nums.size()){
        if(sum==S)res++;
        return;
      }
      recursive(nums, S, res, idx+1, sum+nums[idx]);
      recursive(nums, S, res, idx+1, sum-nums[idx]);
    }


};



