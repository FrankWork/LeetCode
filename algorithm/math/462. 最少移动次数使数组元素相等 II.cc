#include "../template.h"


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /* 找到中位数，让每个数字都变为中位数
        */
       int l=0, r=nums.size()-1;
       int res=0;
       sort(nums.begin(), nums.end());
       while(l<r){
         res += nums[r--]-nums[l++];
       }
       return res;
    }
};

int main(){
  Solution so;
  vector<int> nums{1,2,3};
  cout << so.minMoves2(nums)<<endl;
}