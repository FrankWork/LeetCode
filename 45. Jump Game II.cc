#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void bt(vector<int>& nums, int i, int step, int& min){
      if(i>=nums.size()-1){
        if(min==-1 || min>step){
          min=step;
        }
        return;
      } 
      if(min!=-1 && step>=min){return;}

      for(int j=1;j<=nums[i];j++){
        bt(nums, i+j, step+1, min);
      }
    }
    int jump(vector<int>& nums) {
      int min=-1;

      bt(nums, 0, 0, min);

      return min;
    }
};

void print(int value, int expect){
  if(value==expect) { cout << "success\n";}
  else{cout << value << " " << expect << endl;}
}
int main(){
  Solution so;

  // vector<int> nums{0};
  // print(so.jump(nums), 0);

  // vector<int> nums1{2,1};
  // print(so.jump(nums1), 1); 

  // vector<int> nums2{1,3,2};
  // print(so.jump(nums2), 2); 

  // vector<int> nums3{3,2,1};
  // print(so.jump(nums3), 1);

  // vector<int> nums4{2,3,1};
  // print(so.jump(nums4), 1);

  // vector<int> nums5{2,3,1,1,4};
  // print(so.jump(nums5), 2); 
 
  // vector<int> nums6{2,3,1,1,0};
  // print(so.jump(nums6), 2); 

  // vector<int> nums7{4,1,1,3,1,1,1};
  // print(so.jump(nums7), 2); 

  // vector<int> nums8{4,4,1,3,1,1,1};
  // print(so.jump(nums8), 2); 
  
  // 31s
  vector<int> nums9{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
  print(so.jump(nums9), 0);
}