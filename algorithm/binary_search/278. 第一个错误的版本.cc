#include "template.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
            m位置错误, 查找区间[l, m]
            m位置对，  查找区间[m+1, r]

            退出循环时，l=m, r=l+1
            m错， r=m => l
            m对， l=m+1 => l
        */
       int l=1, r=n;
       while(l<r){
         int m=l+(r-l)/2;
         if(isBadVersion(m)) r=m;
         else l=m+1;
       }
       return l;
    }
};
