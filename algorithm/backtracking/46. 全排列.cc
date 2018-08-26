#include "../template.h"


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      /*  每个词交换到开头位置，进行dfs； 每个词交换到第二个位置，进行dfs
          用idx标记需要交换的位置，下层dfs时，idx加1
      */
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int idx){
        if(idx==nums.size()){
          res.push_back(nums);
          return ;
        }

        for(int i=idx;i<nums.size();++i){
          swap(nums[i], nums[idx]);
          backtrack(nums, res, idx+1);
          swap(nums[i], nums[idx]);
        }
    }
};


int main(){
    vector<int> nums{1,2,3};
    Solution so;
    auto res = so.permute(nums);
    print2d(res);
}