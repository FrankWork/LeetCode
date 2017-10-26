#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size(), m=0;
      int sum=0;
      if(n==1){return sum;}

      for(int i=0;i<n-1;){
        cout << i << endl;
        int m=i;
        for(int j=i;j<i+nums[i];j++){
          if(nums[m]<=nums[j]){
            m=j;
          }
        }
        if(i+nums[i]>=n-1){sum++;break;}
        if(i==m){i+=nums[m];sum++;}
        else{i=m;sum++;}
        
      }
      return sum;
    }
};

void print(int value, int expect){
  if(value==expect) { cout << "success\n";}
  else{cout << value << " " << expect << endl;}
}
int main(){
  Solution so;

  vector<int> nums{0};
  print(so.jump(nums), 0);

  vector<int> nums1{2,1};
  print(so.jump(nums1), 1); 

  vector<int> nums2{1,3,2};
  print(so.jump(nums2), 2); 

  vector<int> nums3{3,2,1};
  print(so.jump(nums3), 1);

  vector<int> nums4{2,3,1};
  print(so.jump(nums4), 1);

  // vector<int> nums5{2,3,1,1,4};
  // print(so.jump(nums5), 2); 
 
  // vector<int> nums6{2,3,1,1,0};
  // print(so.jump(nums6), 2); 

  // vector<int> nums7{4,1,1,3,1,1,1};
  // print(so.jump(nums7), 2); 

  // vector<int> nums7{4,4,1,3,1,1,1};
  // print(so.jump(nums7), 2); 
  

}