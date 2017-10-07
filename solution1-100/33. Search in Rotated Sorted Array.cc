#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int l=0, r = nums.size()-1;
      int m;
      
      while(l<=r){
        m = (l+r)/2;
        if(nums[m] == target){
          return m;
        }else if(nums[l]>nums[m]){// l < pivot < m
          if(target>nums[m] && target<=nums[r]){
            l=m+1;
          }else{
            r=m-1;
          }
        }else { // m < pivot < r
          if(target>=nums[l] && target < nums[m]){
            r=m-1;
          }else{
            l=m+1;
          }
        }
      }
      return -1;
    }
};

void test(Solution &so, vector<int>& nums, int target){
  int idx = so.search(nums, target);

  for(int i=0;i < nums.size();++i){
    cout << nums[i] << " ";
  }
  cout << "\t" << target << "\t" << idx << endl;
}

int main(){
  Solution so;

  vector<int> n1 = {0,1,2,3,4,5,6,7};
  for(t : n1){
    test(so, n1, t);
  }
  test(so, n1, 8);

  vector<int> n2 = {4,5,6,7,0,1,2};
  for(t : n2){
    test(so, n2, t);
  }
  test(so, n2, 8);
  
  vector<int> n3 = {4,5,6,7,8,1,2,3};
  for(t : n3){
    test(so, n3, t);
  }
  test(so, n3, 9);

  vector<int> n4 = {4,5,6,7,8,9,10,1,2,3};
  for(t : n4){
    test(so, n4, t);
  }
  test(so, n4, 11);

  vector<int> n5 = {10,1,2,3,4,5,6,7};
  for(t : n5){
    test(so, n5, t);
  }
  test(so, n5, 9);
}