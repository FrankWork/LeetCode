#include "../template.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      /* 每个数字有两种状态，选/不选
      */
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(res, tmp, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums,
          int level){
        
        res.push_back(tmp);//不选

        for(int i=level;i<nums.size();++i){
          tmp.push_back(nums[i]);//选
          dfs(res, tmp, nums, i+1);
          tmp.pop_back();
        }
    }
};
