#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
      int i=l;
      int small=l-1, large=l;
      
      for(i=l;i<r;++i){
        if(nums[i]<nums[r]){
          ++small;
          swap(nums[i], nums[small]);
          ++large;
        }else if(nums[i]>nums[r]){
          ++large;
        }
      }
      ++small;
      swap(nums[small], nums[r]);
      return small;
    }
    void fastSort(vector<int>& nums, int l, int r){
      // cout << "l, r: " <<  l << " " << r << "\n";
      if (l>=r) return ;
      int p = partition(nums, l, r);
      fastSort(nums, l, p-1);
      fastSort(nums, p+1, r);
    }
    void sortColors(vector<int>& nums) {
        fastSort(nums, 0, nums.size()-1);
    }
};

int main(){
  
  Solution so;
  
  vector<int> nums{
    // 0,0,1,1,2,2
    0,1, 0, 2, 1, 2
  };
  so.sortColors(nums);
  for(int i=0;i<nums.size();++i){
    cout << nums[i] << " ";
  }
  cout << endl;

}