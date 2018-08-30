#include "../template.h"


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        /* dp(i)表示以a(i)结尾的递增区间的个数
           
           a(i)-a(i-1) == a(i-1) - a(i-2)
           则 a(i-2), a(i-1), a(i)为等差数列
           如果已经有 a(i-3),a(i-2),a(i-1)是等差数列，
           那么dp(i)=dp(i-1)+1
           1 2 3 4 5 6
           0 0 1 2 3 4

           3 (1,2,3)
           4 (2,3,4) (1,2,3,4)
           5 (3,4,5) (2,3,4,5) (1,2,3,4,5)
           6 (4,5,6) (3,4,5,6) (2,3,4,5,6) (1,2,3,4,5,6)

        */
       int n=a.size();
       if(n==0)return 0;
       vector<int> dp(n);
       for(int i=2;i<n;++i){
         if(a[i]-a[i-1]==a[i-1]-a[i-2]){
           dp[i]+=dp[i-1]+1;
         }
       }
       return accumulate(dp.begin(), dp.end(), 0);
    }
};

