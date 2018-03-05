#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

template<class T>
void print(vector<T> &vec){
    for(T i: vec){
            cout << i << " ";
        }
        cout << '\n';
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if(n==0)return 0;
      int l=0,r=0;
      
      while(r<n){
        // printf("l:%d r:%d %d %d\n", l, r, nums[l], nums[r]);
        if(nums[l]!=nums[r]){
          l=r;
          ++r;
        }else{
          if(r-l>1){
            for(int i=r;i<n-1;++i){
              nums[i]=nums[i+1];
            }
            --n;
          }else{
            ++r;
          }
        }
        // ++r;
      }
      
      return n;
    }
};


int main(){
  Solution so;
  vector<int> nums{1,1,1,2,2,3};
  cout << so.removeDuplicates(nums) << endl;//5
  print(nums);

  vector<int> nums1{1,1,1};
  cout << so.removeDuplicates(nums1) << endl;//2
  print(nums1);

  vector<int> nums2{1,2,2,2};
  cout << so.removeDuplicates(nums2) << endl;//3
  print(nums2);

  vector<int> nums3{1,1,1,2,2,2,3,3};
  cout << so.removeDuplicates(nums3) << endl; // 6
  print(nums3);

  vector<int> nums4{0,0,0,0,0};
  cout << so.removeDuplicates(nums4) << endl; // 2
  print(nums4);
}