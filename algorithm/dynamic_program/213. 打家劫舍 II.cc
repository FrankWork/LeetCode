#include "../template.h"


class Solution {
public:
    int rob(vector<int>& nums) {
      /* 首尾两家不可同时强，分别去掉首尾，算最大值
      */
        int n = nums.size();
        if(n==0)return 0;
        if(n==1) return nums[0];

        return max(rob_v1(nums, 1, n-1), rob_v1(nums, 0, n-2));
    }

    int rob_v1(vector<int>& nums, int first, int last) {
        /* 定义 dp 数组用来存储最大的抢劫量，
           其中 dp[i] 表示有i个住户时的最大抢劫量。
           dp[i] = max(dp[i-2] + nums[i],   dp[i-1])
        */
        int n=last-first+1;
        if(n==1) return nums[first];

        vector<int> dp(n);
        dp[0]=nums[first];
        dp[1]=max(dp[0], nums[first+1]);
        for(int i=2;i<n;++i){
          dp[i] = max(dp[i-2]+nums[i+first], dp[i-1]);
        }
        // print(dp);
        return dp[n-1];
    }
};


int main(){
  Solution so;
  // vector<int> nums{4,1,2,7,5,3,1};
  vector<int> nums{1,3,1,3,100};
  
  cout << so.rob(nums) << endl;
}