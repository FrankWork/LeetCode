#include "template.h"

void print(vector<bool>& nums){
    for(bool c:nums)
        cout<<c<<" ";
    cout <<endl;
}

void print(string& nums){
    cout <<"  ";
    for(char c:nums)
        cout<<c<<" ";
    cout <<endl;
}

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        /*
            f(i) 表示s[0, i)是否可以分词  
            f(i)：f(j) && s[j,i)在词典中, 0<=j<i,
        */
        int n=s.length();
        vector<bool> dp(n+1, false);
        dp[0]=true;

        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                if(dp[j] && dict.find(s.substr(j, i-j))!= dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(){
  Solution so;


//   string str="leetcode";
//   unordered_set<string> dict={"leet", "code"};
//   cout << so.wordBreak(str, dict)<<endl;


// "bcc dbac bd"
  string str="bccdbacbdacddabbaaaadababadad";
//   string str="bccdbacbd";


  unordered_set<string> dict={"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba",
  "aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd",
  "cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd",
  "cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
  cout << so.wordBreak(str, dict)<<endl;

}