#include "../template.h"


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /* 1..n的组合
           第一层循环确定第一个数字，然后依次dfs
        */
       vector<vector<int>> res;
       vector<int> tmp;
       dfs(n, k, res, tmp, 1);
       return res;
    }
    void dfs(int n, int k, vector<vector<int>> &res, vector<int> &tmp, int level){
      if(tmp.size()==k){
        res.push_back(tmp);
        return ;
      }

      for(int i=level;i<=n;++i){
        tmp.push_back(i);
        dfs(n, k, res, tmp, i+1);
        tmp.pop_back();
      }
    }
};