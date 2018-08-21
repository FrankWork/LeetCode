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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
          /*
            f(i) 表示s[0, i)是否可以分词  
            f(i)：f(j) && s[j,i)在词典中, 0<=j<i,


            f(i, j) 表示s[0, i)可以分词，并且在j处分词
            f(i, j): f(j, k) && s[j,i)在词典里, 0<=j<i, 0<=k<=j

        */
        vector<string> res;
        // string tmp;

        int n=s.length();
        // vector<bool> dp(n+1, false);
        vector<vector<bool>> dp(n+1, vector<bool>(n,false));

        // dp[0]=true;
        for(int i=0;i<n;++i)
            dp[0][i]=true;

        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                string sub=s.substr(j, i-j);
                for(int k=0;k<=j;++k){
                    if(dp[j][k] && dict.find(sub)!= dict.end()){
                        dp[i][j]=true;
                    }
                }
            }
        }
        // for(int i=0;i<=n;++i){
        //     print(dp[i]);
        // }

        vector<string> words;
        dfs(dp, res, words, s, n);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(vector<vector<bool>> &dp, vector<string>& res, 
             vector<string>& words, string &s, int i){
        /* 
            利用dp数组从后往前找出单词
            dp(i, j): 表示s[0, i)可以分词，并且在j处分词
            那么将 s[j,i)保存起来，接着处理s[0,j)
        */
        if(i==0){
            string tmp;
            for(int j=words.size()-1;j>=0;--j){
                // cout << words[j]<<" ";
                tmp+=words[j];
                if(j>0)tmp+=" ";
            }
            // cout <<endl;
            res.push_back(tmp);
            return;
        }
        for(int j=0;j<dp[i].size();++j){
            if(dp[i][j]){
                words.push_back(s.substr(j, i-j));
                dfs(dp, res, words, s, j);
                words.pop_back();
            }
        }
    }
};

int main(){
  Solution so;


  string str="catsanddog";
  unordered_set<string> dict={"cat", "cats", "and", "sand", "dog"};
  vector<string> res = so.wordBreak(str, dict);
  for(string s:res)
    cout << s<<endl;

}
