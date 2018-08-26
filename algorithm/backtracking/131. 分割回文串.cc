#include "../template.h"





class Solution {
public:
    vector<vector<string>> partition(string s) {
      /*
          对每个位置都尝试切分一下，切分后能成回文，则继续向后切分
          用dfs来向后切分，可以回溯
      */
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(res, tmp, s, 0);
        return res;
    }

    void dfs(vector<vector<string>> &res, vector<string> &tmp, string &s, int level){
      if(level == s.length()){
        res.push_back(tmp);
        return;
      }

      for(int i=level;i<s.length();++i){
        if(isPalindrome(s, level, i)){
          tmp.push_back(s.substr(level, i-level+1));
          dfs(res, tmp, s, i+1);//切分剩下的单词
          tmp.pop_back();
        }
      }
    }

    bool isPalindrome(string&s, int first, int last){
      while(first<last){
        if(s[first]==s[last]) {
          first++;last--;
        }else{
          return false;
        }
      }
      return true;
    }
};

int main(){
    Solution so;
    so.partition("aab");
}

