#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

      int n=0;
      for(int i=0;i<nums.size();i++){
        n = max(n-1, nums[i]);
        if(n<=0 && i!=nums.size()-1){
          return false;
        }
      }

      return true;
    }
};

int main(){
  Solution so;
  vector<int> nums{2,3,1,1,4};
  cout << so.canJump(nums) << endl;
  vector<int> nums2{3,2,1,0,4};
  cout << so.canJump(nums2) << endl;

  vector<int> nums3{0,1};
  cout << so.canJump(nums3) << endl;
  return 0;
}