#include "../template.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /* 01背包
            dp(i, j, k)前i个字符串最大数目
            dp(i, j, k) = max( dp(i-1, j, k), dp(i-1, j-n0, k-n1)+1 )
        */
       int n_str = strs.size();
       vector<vector <vector<int> >> dp(n_str+1, 
                                    vector<vector<int>>(m+1, vector<int>(n+1)));

       for(int i=1;i<=n_str;++i){
        //  dp[i][0][0]=1;
         int n0 = 0, n1 = 0;
         for(char c: strs[i-1]){
           if(c=='0') n0++;
           else n1++;
         }
        //  printf("%d %d\n", n0, n1);
        //  cout << strs[i-1]<<endl;
         for(int j=0;j<=m;++j){
           for(int k=0;k<=n;++k){
             dp[i][j][k] = max( dp[i][j][k], dp[i-1][j][k]);
              if(j>=n0 && k>=n1)
                dp[i][j][k] = max( dp[i][j][k], dp[i-1][j-n0][k-n1]+1);
           }
         }
        //  print2d(dp[i]);
        //  cout << endl;
       }


      return dp[n_str][m][n];
    }
};

int main(){
  vector<string> strs{"10", "0001", "111001", "1", "0"};
  Solution so;
  cout << so.findMaxForm(strs, 5, 3)<<endl;
}

