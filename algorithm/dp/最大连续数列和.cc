#include "template.h"

class MaxSum {
public:
    int getMaxSum(vector<int> &A, int n) {
        /* f(i)表示以第i个数字结尾的子数组的最大和
                  A[0]           i=0
           f(i) = f(i-1) + A[i], f(i-1)>0
                  A[i]           f(i-1)<=0
        */
        vector<int> dp(n);
        dp[0]=A[0];
        int best = dp[0];
        for(int i=1;i<n;++i){
            if(dp[i-1]>0) dp[i] = dp[i-1]+A[i];
            else dp[i]=A[i];
            best = max(best, dp[i]);
        }
        return best;
    }
};

int main(){
    MaxSum m;

    vector<int> nums{1,2,3,-6,1}; 
                   //1 3 6 -2 1
    cout << m.getMaxSum(nums, nums.size()) << endl;

    vector<int> nums2{1,-2, 3, 10, -4, 7, 2, -5}; 
                    //1  -1 3  13  9  16 18  3
    cout << m.getMaxSum(nums2, nums2.size()) << endl;

}