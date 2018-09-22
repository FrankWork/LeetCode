#include "../template.h"


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      /* 对每个数字，算出前面数字的乘积和后面数字的乘积
      */
        int n = nums.size();
        vector<int> outs(n);
        vector<int> forward(n);
        vector<int> backward(n);
        forward[0]=1;
        for(int i=1;i<n;++i){
          forward[i] = forward[i-1]*nums[i-1];
        }
        backward[n-1]=1;
        for(int i=n-2;i>=0;--i){
          backward[i] = backward[i+1]*nums[i+1];
        }
        for(int i=0;i<n;++i){
          outs[i] = forward[i] * backward[i];
        }
        
      return outs;
    }
};

int main(){
  Solution so;
  vector<int> nums{1,2,3,4};
  auto outs = so.productExceptSelf(nums);
  print(outs);
}
