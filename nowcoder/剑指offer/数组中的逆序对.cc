#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long res=0;
    int InversePairs(vector<int> &data) {
        // int res=0;
        vector<int> tmp(data.size());
        
        sort(data, 0, data.size()-1, tmp);

        return res%1000000007;
    }

    void sort(vector<int> &nums, int l, int r, vector<int>& tmp){
      if(l<r){
        int m=(l+r)/2;
        sort(nums, l, m, tmp);
        sort(nums, m+1, r, tmp);
        merge(nums, l, m, r, tmp);
      }
    }

    void merge(vector<int>&nums, int l, int m, int r, vector<int>&tmp){
      int i=m,j=r;
      int t=0;
      while(i>=l && j>m){
        if(nums[i]>nums[j]){//m+1, j, r
          res += j-m;
          tmp[t++]=nums[i--];
        }else{
          tmp[t++]=nums[j--];
        }
      }

      while(i>=l){
        tmp[t++]=nums[i--];
      }
      while(j>m){
        tmp[t++]=nums[j--];
      }

      // t=0;
      while(l<=r){
        nums[l++]=tmp[--t];
      }
    }
};

int main(){

}