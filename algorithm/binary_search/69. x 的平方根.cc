#include "template.h"

class Solution {
public:
    int mySqrt(int x) {
        /*
          一个数 x 的开方 z 一定在 0 ~ x 之间，
          并且满足 z == x / z。
          可以利用二分查找在 0 ~ x 之间查找 z。

          1  2  3   4 5 6 7 8
          l  z      m       r
          l  m  r   z
            l/m r   z
             z  lrm
             r  l
        */
       int l=1, r=x;
       int m, z;
       while(l<=r){
         m=l+(r-l)/2;
         z = x/m;
         if(z==m) return z;
         else if(z<m)r=m-1;
         else l=m+1;
       }
       return r;
    }
};

int main(){

}