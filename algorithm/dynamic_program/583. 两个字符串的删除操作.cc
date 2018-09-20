#include "../template.h"

class Solution {
public:
    int minDistance(string a, string b) {
        /* 求最长公共子串，两个单词长度×2 - 最长公共子串长度×2

          dp(i,j) a[0..i], b[0..j]的最长公共子串长度

          dp(i, j) = dp(i-1,j-1)+1,   i==j
                    = max( dp(i-1,j), dp(i, j-1)),
        */
       int na=a.length(), nb=b.length();
       vector<vector<int>> dp(na+1, vector<int>(nb+1));

       for(int i=1;i<=na;++i){
         for(int j=1;j<=nb;++j){
           if(a[i-1]==b[j-1]){
             dp[i][j]=dp[i-1][j-1] + 1;
           }else{
             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
         }
       }
       print2d(dp);
       return na+nb-2*dp[na][nb];
    }
};

int main(){
  Solution so;
  cout <<so.minDistance("a", "b")<<"\n";
}
