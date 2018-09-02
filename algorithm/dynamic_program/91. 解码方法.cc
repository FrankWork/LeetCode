#include "../template.h"

class Solution {
public:
    int numDecodings(string s) {
      /* dp(i): i位置结束可能的解码数目
         dp(i) += dp(i-1) + 1, 1-9
         dp(i) += dp(i-2) + 1, 1x, 2x
      */
      int n=s.length();
      if(n==0)return 0;

        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]= s[0]=='0'?0:1;
        for(int i=2;i<=n;++i){
          if(s[i-1]!='0') dp[i]+=dp[i-1];
          if(s[i-2]=='0')continue;
          if(s[i-2]=='1'||(s[i-2]=='2' && s[i-1]<'7') ) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};


int main(){
  Solution so;
  cout << so.numDecodings("0")<<endl;//0
  cout << so.numDecodings("01")<<endl;//0
  cout << so.numDecodings("230")<<endl;//0
  cout << so.numDecodings("10")<<endl;//1
  cout << so.numDecodings("12")<<endl;//2
  cout << so.numDecodings("226")<<endl;//3
  cout << so.numDecodings("27")<<endl;//1
  
  
  
}

