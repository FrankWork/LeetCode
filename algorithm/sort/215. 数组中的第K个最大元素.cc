#include "template.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sortKth(nums, 0, nums.size()-1, k);
        return nums[k-1];
    }
    void sortKth(vector<int>& nums, int l, int r, int k){
      /*
        l..p..k..r  (p+1, r)
        l..k..p..r  (l, p-1)
      */
      if(l<r){
        int p=partition(nums, l, r);
        if(p<k){
          sortKth(nums, p+1, r, k);
        }else{
          sortKth(nums, l, p-1, k);
        }
      }
    }
    void sort(vector<int>& nums, int l, int r){
      if(l<r){
        int p=partition(nums, l, r);
        sort(nums, l, p-1);
        sort(nums, p+1, r);
      }
    }
    int partition(vector<int>& nums, int l, int r){
      /*  划分为两个区域，大于划分节点的区域a， 小于划分节点的区域b
         i: 区域a的结束位置的下一个位置
         j: 区域b的结束位置的下一个位置
      */
      int i=l, j=l;
      int x=nums[r];

      for( ;j<r;j++){
        if(nums[j]>x){
          swap(nums[i], nums[j]);
          i++;
        }
      }
      swap(nums[i], nums[r]);
      return i;
    }
};


int main(){
    Solution so;
    // vector<int> nums{3,2,1,5,6,4};
    // cout << so.findKthLargest(nums, 2)<<endl;
    // so.sort(nums, 0, nums.size()-1);
    // print(nums);


    vector<int> nums{3,2,3,1,2,4,5,5,6};
    // so.sort(nums, 0, nums.size()-1);
    cout << so.findKthLargest(nums, 4)<<endl;
    print(nums);

}