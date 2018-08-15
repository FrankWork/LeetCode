#include "template.h"

int minNumberOfCoins(vector<int>& coins, int money){
    /*
        f(i) 表示待找零总钱数为i时，需要的最小硬币数
        
        f(i) = min( f(i-coins[j]) )+1, 0<=j<n, i-coins[j]>=0
    */
    int n = coins.size();
    vector<int> dp(money+1, INT_MAX);
    dp[0]=0;

    for(int i=1;i<=money;++i){
        for(int j=0;j<n;++j){
            int t=i-coins[j];
            if(t>=0 && dp[t] != INT_MAX){
                dp[i] = min(dp[t], dp[i]);
            }
        }
        if(dp[i]!=INT_MAX)
            dp[i]++;
    }
    // print(dp);
    return dp[money];
}

int main(){
    vector<int> coins{5,2,3};
    cout << minNumberOfCoins(coins, 20) << endl;//4

    vector<int> coins2{1,3,4};
    cout << minNumberOfCoins(coins2, 6) << endl;//2

    // cout << INT_MAX<<endl;
}