#include "../template.h"


class Solution {
public:
    int numSquares(int n) {
      /* 方法1：bfs
         方法2：动态规划

         dp(i)表示组成i的完全平方数的最小个数
         dp(i) = min{dp(j)} + 1, if j+x=i
      */
     vector<int> squares=getSquares(n);
     vector<int> dp(n+1);
     dp[0]=0;
    //  dp[1]=1;
    //  dp[2]=1;
     for(int i=1;i<=n;++i){
       dp[i] = numeric_limits<int>::max();
       for(int s:squares){
         if(i-s>=0){
           break;
         }
         dp[i] = min(dp[i], dp[i-s]+1);
       }
     }

     return dp[n];
    }

    vector<int> getSquares(int n){
      // 生成完全平方数
      // 1, 4, 9, 16,
      vector<int> res;
      for(int i=1; ;i++){
        int t=i*i;
        if(t>n) break;
        res.push_back(t);
      }
      return res;
    }
};



vector<int> squares(int n){
  vector<int> res;
  int diff=1;
  int square=3;
  while(square<=n){
    res.push_back(square);
    square += diff;
    diff+=2;
  }
  return res;
}

int main(){
  Solution so;
  cout << so.numSquares(12)<<endl;
}