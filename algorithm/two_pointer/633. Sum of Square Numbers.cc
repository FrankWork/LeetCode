#include <iostream>
#include <vector>
#include <cmath>

class Solution{

    bool judgeSquareSum(int c){
        /*
            l, r [0...sqrt(c)]
        */
       int n = sqrt(c);
       int l=0, r=n;
       
       while(l<=r){
           int t=l*l+r*r;
           if(t==c){
               return true;
           }else if(t<c)l++;
           else r--;
       }
       return false;
    }
};
main(){

}