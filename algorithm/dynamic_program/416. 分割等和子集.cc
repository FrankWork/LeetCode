#include "../template.h"


class Solution {
public:
    bool canPartition(vector<int>& a) {
      /* 转换为0,1背包问题，让背包的容量为数组总和的一半
      */
        int n=a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum%2!=0) return false;

        return get_sum_set(a,  sum/2);
    }

    bool get_sum_set(vector<int> &a, int target){
      /* 找到非空子集合，使和为target

         dp[i]表示是否有子数组，其总和为i
         dp(i) = dp(i-v), v in a

         确保每个数字只能用一次，先遍历a，再遍历v，遍历v时要从后遍历
      */
     vector<bool> dp(target+1);
     dp[0]=true;
     
     for(int v: a){
       for(int i=target;i>0;--i){
         if(i-v>=0 && dp[i-v]) dp[i] = dp[i-v];
       }
        // print(dp);
     }
    
     return dp[target];

    } 
};

int main(){
  Solution so;
  vector<int> a{1,5,11,5};
  cout << so.canPartition(a) << endl;
}