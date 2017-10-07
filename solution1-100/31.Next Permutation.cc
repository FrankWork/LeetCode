#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
// 1,3,2 → 2,1,3
void print(vector<int>& nums){
  int n = nums.size();
  for(int i=0;i < n;++i){
    cout << nums[i] << (i==n-1 ? "\n" : ",");
  }
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      int i;

      // make the nums greater
      for(i=n-1;i > 0;i--){
        if(nums[i]>nums[i-1]){// find the first decreasing element nums[i-1]
          for(int j=n-1;j >= i;j--){// find the element just larger than nums[i-1]
            if(nums[i-1] < nums[j]){
              swap(nums[i-1], nums[j]);
              break;
            }
          }
          break;
        }
      }
      // reverse nums[i:n]
      int mid = i + (n-i)/2;
      for(int j=i;j < mid;j++){
        swap(nums[j], nums[n-j-1+i]);
      }

      for(int i=0;i < n;++i){
        cout << nums[i] << (i==n-1 ? "\n" : ",");
      }
    }
};


int main(){
  Solution so;
  vector<int> nums={1,2,3};
  so.nextPermutation(nums);

  vector<int> nums2={3,2,1};
  so.nextPermutation(nums2);

  vector<int> nums3={1,1,5};
  so.nextPermutation(nums3);

  vector<int> nums4={1,3,2};
  so.nextPermutation(nums4);

  // sort(nums4.begin(), nums4.end());// [] (int const& a, int const& b) { return a < b; }

  // for(n : nums4){
  //   cout << n << " ";
  // }
  // cout << endl;
}