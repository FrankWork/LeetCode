#include "../template.h"


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /* dp(i) 凑成i钱数所需的最小硬币数目
           dp(i) = min( dp(i-c)+1)
        */
       int _max = amount+1;
       vector<int> dp(amount+1, _max);
       dp[0]=0;

       for(int i=1;i<=amount;++i){
         dp[i]=_max;
         for(int c: coins){
          //  printf("i-c: %d\n", i-c);
           if(i-c>=0)
              dp[i] = min(dp[i], dp[i-c]+1);
         }
       }
       if(dp[amount]==_max) dp[amount]=-1;
      //  print(dp);
       return dp[amount];
    }
};

int main(){
  Solution so;

  // vector<int> coins{2147483647};
  // cout << so.coinChange(coins, 2) <<endl;

  vector<int> coins{2};
  cout << so.coinChange(coins, 3) <<endl;
  
}
