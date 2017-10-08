#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int l=0, r=nums.size()-1, m;
      while(l<=r){
        m = (l+r)/2;
        if(target < nums[m]){
          r=m-1;
        }else if(target > nums[m]){ 
          l=m+1;
        }else{//if(nums[m] == target)
          break;
        }
      }
      if(nums[m]<target){
        m++;
      }

      return m;
    }
};

void test(Solution &so, vector<int>& nums, int target, int ans){
  int result = so.searchInsert(nums, target);

  for(int i=0;i < nums.size();++i){
    cout << nums[i] << " ";
  }
  cout << "\t" << target << "\t" << result;
  if(result!=ans){
    cout << "\t" << ans ;
  } 
  cout << endl;
}

int main(){
  Solution so;

  vector<int> n1 = {1,3,5,6};
  test(so, n1, 5, 2);
  test(so, n1, 2, 1);
  test(so, n1, 7, 4);
  test(so, n1, 0, 0);
 
  
}
