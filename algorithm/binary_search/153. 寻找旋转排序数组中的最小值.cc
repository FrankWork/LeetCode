#include "template.h"


class Solution {
public:
    int findMin(vector<int>& a) {
    /*  数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]
        a[m]<a[r]    查找[l, m]
        a[m]>a[r]    查找[m+1, r]

        退出时, l=m, r=l+1
        a[m]<a[r]  r=m  => l
        a[m]>a[r]  l=m+1 => l
    */
      int l=0, r=a.size()-1;
      while(l<r){
        int m=l+(r-l)/2;
        if(a[m]<a[r]) r=m;
        else l=m+1;
      }
      return a[l];
    }
};


int main(){

}