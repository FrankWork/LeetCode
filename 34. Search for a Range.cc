#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void binarySearch(vector<int>& nums, vector<int>& result, 
      int target, int start, int end){
        if(start==end){
          if(nums[start]==target){
            if(start<result[0]){result[0]=start;}
            if(start>result[1]){result[1]=start;}
          }
          return;
        }

        int l=start, r=end, m;
        while(l<=r){
          m = (l+r)/2;
          if(target < nums[m]){
            r=m-1;
          }else if(target > nums[m]){ 
            l=m+1;
          }else{//if(nums[m] == target)
            if(m<result[0]){result[0]=m;}
            if(m>result[1]){result[1]=m;}
            binarySearch(nums, result, target, l, m-1);
            binarySearch(nums, result, target, m+1, r);
            break;
          }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      int size = nums.size();
      vector<int> result = {size, -1};
      
      binarySearch(nums, result, target, 0, size-1);

      // find one target index
      if(result[0]==size){
        result[0] = -1;
      }
      
      return result;
    }
};

void test(Solution &so, vector<int>& nums, int target){
  vector<int> result = so.searchRange(nums, target);

  for(int i=0;i < nums.size();++i){
    cout << nums[i] << " ";
  }
  cout << "\t" << target << "\t" << result[0]<<","<<result[1] << endl;
}

int main(){
  Solution so;

  vector<int> n1 = {5, 7, 7, 8, 8, 10};
  test(so, n1, 5);
  test(so, n1, 7);
  test(so, n1, 8);
  test(so, n1, 10);
  test(so, n1, 11);

  vector<int> n2 = {5, 6,6, 7, 8, 8, 10};
  test(so, n2, 5);
  test(so, n2, 6);
  test(so, n2, 7);
  test(so, n2, 8);
  test(so, n2, 10);
  test(so, n2, 11);
  
}
