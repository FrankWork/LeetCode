#include "../template.h"

bool cmp(vector<int>&a, vector<int>&b){
  return a[0]<b[0];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        /* 300.最长上升子序列
        */
       int n=a.size();
       if(n==0)return 0;
       sort(a.begin(), a.end(), cmp);
       vector<int> dp(n, 1);
       for(int i=0;i<n;++i){
         for(int j=0;j<i;++j){
           if(a[i][0]>a[j][1])
              dp[i] = max(dp[i], dp[j]+1);
         }
       }
       int res=0;
       for(int v:dp) res=max(res, v);
       return res;
    }
};