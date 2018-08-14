#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> &nums,int sum) {
        int l=0,r=nums.size()-1;
        vector<int> res;
        while(l<r){
          int t=nums[l]+nums[r];
          if(t==sum){
            res.push_back(nums[l]);
            res.push_back(nums[r]);
            return res;
          }else if(t<sum){
            ++l;
          }else{
            --r;
          }
        }
        return res;
    }
};