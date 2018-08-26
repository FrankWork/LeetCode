#include "../template.h"


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*  每个词交换到开头位置，进行dfs； 每个词交换到第二个位置，进行dfs
          用idx标记需要交换的位置，下层dfs时，idx加1
      */
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, int idx){
      /* 如果[idx, i-1]区间里有和i相同的元素，则忽略当前i
      */
        if(idx==nums.size()){
          res.push_back(nums);
          return ;
        }

        for(int i=idx;i<nums.size();++i){
          // 去重
          bool same=false;
          for(int j=idx;j<i;j++){
            if(nums[i]==nums[j]) {
              if(i==j) cout << "fuck"<<endl;
              same=true;
              break;
            }
          }
          if(same) continue;
          

          swap(nums[i], nums[idx]);
          backtrack(nums, res, idx+1);
          swap(nums[i], nums[idx]);
        }
    }
};


int main(){
    Solution so;
    vector<int> nums{2,2,1,1};

    auto res = so.permuteUnique(nums);
    print2d(res);
}