#include "../template.h"

class Solution {
public:
    string convertToBase7(int num) {
        /* 辗转相除法
          100 -> 202
          100除以7，商14余2，然后用14除以7，商2余0，再用2除以7，商0余2

          -7 -> -10
          7除以7, 商1余0, 然后用1除以7，商0余1
        */
       if(num==0)return "0";
       string res;
       bool neg = num < 0;
       if(neg) num = -num;

       while(num){
         res = to_string(num%7) + res;
         num/=7;
       }
       if(neg) return "-"+res;
       return res;
    }
};

