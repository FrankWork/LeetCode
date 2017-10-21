#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    int trap(vector<int>& height) {
      int l=0, r=height.size()-1;
      int lmax=0, rmax=0;
      int sum=0;

      while(l<=r){
        if(height[l]<height[r]){
          if(lmax < height[l]){lmax=height[l];}
          sum += lmax-height[l];
          l++;
        }else{
          if(rmax < height[r]){rmax=height[r];}
          sum += rmax-height[r];
          r--;
        }
      }
      return sum;
    }
};

int main(){
  Solution so;
  vector<int> nums={0,1,0,2,1,0,1,3,2,1,2,1};// 6
  int result = so.trap(nums);
  cout << result << endl << endl;

  vector<int> nums1={};// 0
  result = so.trap(nums1);
  cout << result << endl << endl;

  vector<int> nums2={2,0,2};// 2
  result = so.trap(nums2);
  cout << result << endl << endl;
  
  
  vector<int> nums3={5,4,1,2};// 1
  result = so.trap(nums3);
  cout << result << endl << endl;

  vector<int> nums4={5,2,1,2,1,5};// 14
  result = so.trap(nums4);
  cout << result << endl << endl;
}