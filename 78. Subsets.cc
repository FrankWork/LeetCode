#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void print(vector<vector<int>> &path){
    for(auto vec: path){
        for(int i: vec){
            cout << i << " ";
        }
        cout << '\n';
    }
}

class Solution {
public:
    void subsets(vector<int>& nums, int start, int k, vector<int>& vec, vector<vector<int>>&res){
      if(k==0){
        res.push_back(vec);
        return;
      }
      for(int i=start;i<nums.size()-k+1;++i){
        // printf("k:%d i:%d nums[i]:%d\n", k, i, nums[i]);
        vec.push_back(nums[i]);
        // swap(nums[i], nums[start]);
        subsets(nums, i+1, k-1, vec, res);
        // swap(nums[i], nums[start]);
        vec.pop_back();
      }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        for(int i=0;i<=nums.size();++i)
          subsets(nums, 0, i, vec, res);
        return res;
    }
};

int main(){
  Solution so;
  vector<int> nums{1,2,3};
  auto res = so.subsets(nums);
  print(res);
}