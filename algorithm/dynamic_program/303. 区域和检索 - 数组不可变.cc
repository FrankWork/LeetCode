#include "../template.h"

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        int res=0;
        for(int i=0;i<nums.size();++i){
            res+=nums[i];
            sum.push_back(res);
        }
    }
    
    int sumRange(int i, int j) {
        //求区间 i ~ j 的和，可以转换为 sum[j] - sum[i-1]，其中 sum[i] 为 0 ~ i 的和。
        if(i==0) return sum[j];
        return sum[j]-sum[i-1];
    }
};



int main(){
  
}