#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
        vector<int> res(k);
        quick_sort(input, 0, input.size()-1, k);
        for(int i=0;i<k;++i){
          res[i]=input[i];
        }
        return res;
    }

    void quick_sort(vector<int>& nums, int l, int r, int k){
      if(l<r){
        int p = partition(nums, l, r);
        if(k<p){//l,k, p, r
          quick_sort(nums, l, p-1, k);
          // quick_sort(nums, p+1, k, k);
        }else{// l, p, k, r
          quick_sort(nums, l, p-1, k);
          quick_sort(nums, p+1, r, k);
        } 
      }
    }

    int partition(vector<int>& nums, int l, int r){
      int sm=l,bg=l;
      int x=nums[r];
      for(;bg<r;++bg){
        if(nums[bg]<=x){
          swap(nums[sm], nums[bg]);
          ++sm;
        }
      }
      swap(nums[sm], nums[r]);
      return sm;
    }

};

int main(){
  Solution so;
  vector<int> nums{4,5,1,6,2,7,3,8};
  vector<int> res = so.GetLeastNumbers_Solution(nums, 10);
  for(auto n:res)
    cout<<n<<endl;
}