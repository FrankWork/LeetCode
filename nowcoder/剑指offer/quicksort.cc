#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int partition(vector<int>&nums, int l, int r){
      int x=nums[r];
      int sm=l;
      for(int lg=l;lg<r;++lg){
        if(nums[lg]<=x){
          swap(nums[sm], nums[lg]);
          ++sm;
        }
      }
      swap(nums[sm], nums[r]);
      return sm;
    }

    void quickSort(vector<int> &nums, int l, int r) {
        int p = partition(nums, l, r);
        if(p<r){
          quickSort(nums, l, p-1);
          quickSort(nums, p+1, r);
        }
        
    }
};

int main(){
  Solution so;
  vector<int> nums{4,5,1,6,2,7,3,};
  so.quickSort(nums, 0, nums.size()-1);
  for(auto n:nums)
  cout<<n<<endl;
}