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
      */
        int n=a[0];
        for(int i=1;i<a.size();++i){
          n^=a[i];
        }
        return n;
    }
};