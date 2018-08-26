#include "template.h"

class Solution {
public:
    int singleNonDuplicate_xor(vector<int>& a) {
      /* 异或消除重复数字
      */
        int n=a[0];
        for(int i=1;i<a.size();++i){
          n^=a[i];
        }
        return n;
    }

    int singleNonDuplicate(vector<int>& a) {
      /* 二分查找
         设i为目标的位置，如果
          中位数m为偶数，且 m+1<i, 则 a[m]==a[m+1]
                         m+1=i,  a[m] != a[m+1]
                         m+1>i,  a[m] != a[m+1]
                 所以，a[m]==a[m+1], 则 i区间为[m+2, r], l=m+2
                      a[m]!=a[m+1], 则 i区间为[l, m]    r=m
                 因为 赋值表达式r=m，则 循环条件为l<r

                 退出条件，l==m, r==l+1
                 a[l]==a[r], l=r+1 => l
                 a[l]!=a[r], r=l   => l
      */
        int l=0, r=a.size()-1;
        while(l<r){
          int m=l+(r-l)/2;
          if(m%2!=0) m--;
          if(a[m]==a[m+1]) l=m+2;
          else r=m;
        }
        return a[l];
    }
};