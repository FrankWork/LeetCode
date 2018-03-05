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
      if(nums.size()<=2){
        return nums.size();
      }
      int n=2;
      for(int i=2;i<nums.size();++i){
        // printf("i:%d n:%d\n", i, n);
        if(nums[i]!=nums[n-2]){
          nums[n]=nums[i];
          ++n;
        }
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