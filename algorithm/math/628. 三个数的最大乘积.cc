#include "../template.h"


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      /* 三个最大的正数相乘
         最大的正数*两个最小的负数
      */
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        int min1=INT_MAX, min2=INT_MAX;

        for(int t:nums){
          if(t>max1){
            max3=max2;
            max2=max1;
            max1=t;
          }else if(t>max2){
            max3=max2;
            max2=t;
          }else if(t>max3){
            max3=t;
          }

          if(t<min1){
            min2=min1;
            min1=t;
          }else if(t<min2){
            min2=t;
          }
        }
        
        // printf("%d %d %d\n", max1, max2, max3);
        // printf("%d %d\n", min1, min2);
        
        return max(max1*max2*max3, max1*min1*min2);
    }
};

int main(){
  Solution so;
  vector<int> nums{1,2,3,4};
  cout << so.maximumProduct(nums) << endl;

  vector<int> nums2{4,2,5,5,6,0};
  cout << so.maximumProduct(nums2) << endl;
}
