#include "../template.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        /* 定义 dp 数组用来存储最大的抢劫量，
           其中 dp[i] 表示有i个住户时的最大抢劫量。
           dp[i] = max(dp[i-2] + nums[i],   dp[i-1])
        */
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(dp[0], nums[1]);
        for(int i=2;i<n;++i){
          dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        print(dp);
        return dp[n-1];
    }
};

int main(){
  Solution so;
  // vector<int> nums{4,1,2,7,5,3,1};
  vector<int> nums{3,1,3,100};
  
  cout << so.rob(nums) << endl;
}