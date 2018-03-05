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
    bool search(vector<int>& nums, int target, int l, int r){
      // printf("l:%d r:%d\n", l, r);
      if(l>r){
        return false;
      }
      int m = (l+r)/2;
      if(nums[m]==target){
        return true;
      }
      if(search(nums, target, l, m-1)){
        return true;
      }
      if(search(nums, target, m+1, r)){
        return true;
      }
      return false;
    }
    bool search(vector<int>& nums, int target) {
      return search(nums, target, 0, nums.size()-1);  
    }
};


int main(){
  Solution so;

  vector<int> nums{4, 5, 6, 7, 0, 0, 1, 2};
  for(int n:nums)
    cout << so.search(nums, n) << endl;
  cout << so.search(nums, 11) << endl;
}