#include "../template.h"

class Solution {
public:
    int minSteps(int n) {
        /* 最多n次：拷贝1次，复制n-1次
           c:copy p:paste
           4: c1p3 4次
              c1p1 -> AA c1p1 AAAA 4次
           5: c1p4 5次
           6: c1p1-> AA  c1p2 A*6  5次
              c1p2-> AAA c1p1 A*6  5次
           10:  c1p1 -> AA  c1p4 A*10 7次
                c1p5 -> A*5 c1p1 A*10 7次
        找到n的因子z，先拼成z，再复制n/z次，
        找到n的所有因子，计算操作数，找出其中最小的那个

        24 ms
        */
       if(n==1) return 0;

       int res=n;
       for(int z=2;z<n;++z){
           if(n%z==0){//因子
             res = min(res, minSteps(z)+n/z);
           }
       }
       return res;
    }

    int minSteps_dp(int n) {
        /* 最多n次：拷贝1次，复制n-1次
           c:copy p:paste
           4: c1p3 4次
              c1p1 -> AA c1p1 AAAA 4次
           5: c1p4 5次
           6: c1p1-> AA  c1p2 A*6  5次
              c1p2-> AAA c1p1 A*6  5次
           10:  c1p1 -> AA  c1p4 A*10 7次
                c1p5 -> A*5 c1p1 A*10 7次
        找到n的因子z，先拼成z，再复制n/z次，
        找到n的所有因子，计算操作数，找出其中最小的那个

        80 ms
        */
       if(n==1) return 0;

       vector<int> dp(n+1);
       for(int i=2;i<=n;++i){
           dp[i] = i;
           for(int j=1;j<=i-1;j++){
               if(i%j==0){
                   dp[i] = min(dp[i], dp[j]+i/j);
               }
           }
       }
       return dp[n];
    }
};

