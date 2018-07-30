#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sort(vector<int> &nums, int l, int r, vector<int>& tmp){
      if(l<r){
        int m=(l+r)/2;
        sort(nums, l, m, tmp);
        sort(nums, m+1, r, tmp);
        merge(nums, l, m, r, tmp);
      }
    }

    void merge(vector<int>&nums, int l, int m, int r, vector<int>&tmp){
      int i=l,j=m+1;
      int t=0;
      while(i<=m && j<=r){
        if(nums[i]<nums[j]){
          tmp[t++]=nums[i++];
        }else{
          tmp[t++]=nums[j++];
        }
      }

      while(i<=m){
        tmp[t++]=nums[i++];
      }
      while(j<=r){
        tmp[t++]=nums[j++];
      }

      t=0;
      while(l<=r){
        nums[l++]=tmp[t++];
      }
    }
};

int main(){

}