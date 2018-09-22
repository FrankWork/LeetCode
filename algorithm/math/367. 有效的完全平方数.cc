#include "../template.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
      /* 1 4 9 16
         间隔：3 5 7, 间隔为等差数列

         或者二分查找，注意int会溢出
      */
    //  long i=1,t=3;
    //  while(i<num){
    //    i+=t;
    //    t+=2;
    //  }
    //  return i==num;
        int l=1, r=num;
        while(l<=r){
          long m=l+(r-l)/2;
          long t=m*m;
          if(t==num)return true;
          else if(t<num)l=m+1;
          else r=m-1;
        }
        return false;
    }
};

int main(){
  Solution so;
  cout << so.isPerfectSquare(81)<<endl;
  
  cout << so.isPerfectSquare(2147483647)<<endl;
}