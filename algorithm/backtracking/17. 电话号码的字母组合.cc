#include "../template.h"

class Solution {
public:
    vector<string> keys{"", "", "abc", "def", "ghi", "jkl", "mno",
                           "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        /* 回溯法：
              在访问一个新元素进入新的递归调用时，需要将新元素标记为已经访问
              但是在递归返回时，需要将元素标记为未访问
          
          遍历每个数字，对每个数字对应的按键字符候选都尝试一遍
        */
       
       vector<string> res;
       backtrack(digits, res, "", 0);
       return res;
    }

    void backtrack(string &digits, vector<string> &res, string tmp, int idx){
      if(idx>=digits.length()){
        if(tmp.length()!=0) res.push_back(tmp);
          return;
      }
      int d = digits[idx]-'0';
      string &s=keys[d];
      for(int i=0;i<s.length();++i){
        backtrack(digits, res, tmp+s[i], idx+1);
      }
    }
};

int main(){

}