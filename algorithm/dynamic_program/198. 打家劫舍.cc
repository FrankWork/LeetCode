#include "../template.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        /* 定义 dp 数组用来存储最大的抢劫量，
           其中 dp[i] 表示有i个住户时的最大抢劫量。
           dp[i] = max(dp[i-2], dp[i-3]) + nums[i]
        */
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[1];

        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;++i){
          dp[i] = 
        }
    }
};

int main(){

}