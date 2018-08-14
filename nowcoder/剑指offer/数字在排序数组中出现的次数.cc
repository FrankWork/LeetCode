#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> &data ,int k) {
        int l=binary_search(data, k-0.5);
        int r=binary_search(data, k+0.5);
        // printf("%d %d\n", l, r);
        return r-l;
    }

    int binary_search(vector<int> &nums, double k){
      int l=0, r=nums.size()-1;
      int m;
      while(l<=r){
        m=(l+r)/2;
        if(nums[m]<k){
          l=m+1;
        }else{
          r=m-1;
        }
      }
      return l;
    }
};

int main(){
  vector<int> nums{1,2,3,3,3,3,4,5};
  Solution so;
  cout << so.GetNumberOfK(nums, 3)<<endl;
}