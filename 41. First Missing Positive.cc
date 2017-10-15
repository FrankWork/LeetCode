#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      if(nums.size()==0){return 1;}
        int idx = 0;
        int n = nums.size()-1;
        // move min to nums[0], move neg to end
        for(int i=0;i<=n;i++){
          if(nums[i]<=0){
            swap(nums[i], nums[n]);
            n--;
            i--;
          }else if(nums[idx]>nums[i]){
            idx=i;
          }
        }
        if(idx != 0){
          swap(nums[idx], nums[0]);
        }
        idx=0;
        for(int i=idx;i<=n;i++){
          if(nums[i]==nums[idx]+1){
            idx++;
            swap(nums[i], nums[idx]);
            i=idx;
          }
        }
        if(nums[0]!=1){return 1;}
        return nums[idx]+1;
    }
};

int main(){
  Solution so;
  vector<int> nums={1,2,0};// 3
  int result = so.firstMissingPositive(nums);
  cout << result << endl << endl;

  vector<int> nums2={3,4,-1,1};// 2
  result = so.firstMissingPositive(nums2);
  cout << result << endl << endl;

  vector<int> nums3={5,4,-1,2};// 1
  result = so.firstMissingPositive(nums3);
  cout << result << endl << endl;

  vector<int> nums4={5,4,1,2};// 3
  result = so.firstMissingPositive(nums4);
  cout << result << endl << endl;


  vector<int> nums5={-1,4,2,1,9,10};// 3
  result = so.firstMissingPositive(nums5);
  cout << result << endl << endl;

  vector<int> nums6={};// 1
  result = so.firstMissingPositive(nums6);
  cout << result << endl << endl;

  
}