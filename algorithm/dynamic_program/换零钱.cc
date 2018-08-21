#include "template.h"

class Exchange {
public:
    int countWays(vector<int> coins, int n, int x) {
        /* 
           v1:
            f(i, j) 用硬币0..i组成j钱数的方案数
                      不用i硬币    用了i硬币
            f(i, j) = f(i-1, j) + f(i, j-coins[i]), j-coins[i]>=0
                      f(i-1, j)                   , j-coins[i]<0
        */
        vector<vector<int>> dp(n, vector<int>(x+1));
        // 钱数为0
        for(int i=0;i<n;++i){
            dp[i][0]=1;
        }
        //只使用硬币0
        for(int j=0; j*coins[0]<=x;++j){
            dp[0][j*coins[0]] = 1;
        }
        // print2d(dp);

        for(int i=1;i<n;++i){
            for(int j=1;j<=x;++j){
                if(j-coins[i]>=0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                else
                    dp[i][j] = dp[i-1][j];

            }
        }
        // print2d(dp);
        return dp[n-1][x];
    }
    int countWays_v2(vector<int> coins, int n, int x) {
        /* 
           v2:
            f(i) 组成i钱数的方案数

            f(i) = sum( f(i-coins[j]) ),  0<=j<n

        */
       vector<int> dp(x+1);
       dp[0]=1;
       for(int i=0;i<n;++i){
           for(int j=0; j+coins[i]<=x ;++j){
               dp[j+coins[i]] += dp[j];
           }
       }
    //    print(dp);
       return dp[x];
    }
};

int main(){
    Exchange e = Exchange();

    vector<int> coins{5,10,25,1};
    cout << e.countWays(coins, coins.size(), 15) << endl;// 6
    cout << e.countWays_v2(coins, coins.size(), 15) << endl;// 6

    // cout << e.countWays(coins, coins.size(), 0) << endl;// 1
}

