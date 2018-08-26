#include "../template.h"


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
        /* 按正常的dfs流程走完之后，再判断下一个是否重复
        */
        
        res.push_back(tmp);//不选

        for(int i=level;i<nums.size();++i){
          tmp.push_back(nums[i]);//选
          dfs(res, tmp, nums, i+1);
          tmp.pop_back();
          while(i+1<nums.size() && nums[i]==nums[i+1])
              ++i;// 忽略重复的数
        }
    }
};

