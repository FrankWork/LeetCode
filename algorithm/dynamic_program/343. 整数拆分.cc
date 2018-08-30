#include "../template.h"

class Solution {
public:
    int integerBreak(int n) {
        /* dp(i)表示i分割后的最大乘积
           i>=8  dp(i) = 3*dp(i-3), 先分出一个3
        */        
       vector<int> dp{0, 1, 1, 2, 4, 6, 9, 12};
      //  dp.reserve(n);
      //  dp.resize(n);
       for(int i=8;i<=n;++i){
        //  dp[i] = 3*dp[i-3];
         dp.push_back(3*dp[i-3]);
       }
       return dp[n];
    }
};

int main(){
  Solution so;
  cout << so.integerBreak(34) <<endl;
}