#include "../template.h"

int knapsack(int W, int N, vector<int>& weights, vector<int>& values) {
  /* 背包容量W, 使背包装物品的总价值最大，N件物品有两个属性：体积 w 和价值 v
     dp[i][j] 表示前 i 件物品体积不超过 j 的情况下能达到的最大价值，
     第 i 件物品可添加也可以不添加，取决于哪种情况下最大价值更大
     dp(i,j) = max(dp(i-1, j), dp(i-1, j-w)+v)
  */
    vector<vector<int>> dp(N+1, vector<int>(W+1));
    for (int i = 1; i <= N; i++) {
        int w = weights[i - 1], v = values[i - 1];
        for (int j = 1; j <= W; j++) {
            if (j >= w) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][W];
}

int knapsack_v2(int W, int N, vector<int>& weights, vector<int>& values) {
    vector<int> dp(W+1);

    for (int i = 1; i <= N; i++) {
        int w = weights[i - 1], v = values[i - 1];
        for (int j = W; j >= 1; j--) {
            if (j >= w) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    return dp[W];
}