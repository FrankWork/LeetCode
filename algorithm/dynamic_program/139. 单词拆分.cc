#include "../template.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /* 单词的使用次数没有限制，是完全背包问题
           01背包对物品的迭代在最外层，完全背包在最里层

           dp(i) 前i个字符是否可以用字典表示
          
           dp(i) = dp(j) and s(j, i] in dict, 0<=j<i
        */
       set<string> dict(wordDict.begin(), wordDict.end());

       int n=s.length();
       vector<bool> dp(n+1);
       dp[0]=true;

       for(int i=1;i<=n;++i){
         
         for(int j=0;j<i;++j){
           string tmp = s.substr(j, i-j);
           cout << tmp << endl;
           if(dp[j] && dict.find(tmp)!=dict.end()){
             dp[i]=true;
             break;
           }
         }
       }
      //  print(dp);
       return dp[n];
    }
};

int main(){
  Solution so;
  vector<string> d{"leet", "code"};
  so.wordBreak("leetcode", d);
}