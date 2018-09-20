#include "../template.h"


class Solution {
public:
    string toHex(int num) {
        /* 转换为16进制，负数用补码(取反加一)表示
          26 -> 1a
          -1 -> ffffffff

          可以用辗转相除法，但是负数不好处理
          可以按位处理，每次取最右边4位，4位正好可以表示16进制
          负数转化为无符号数，防止右移时增加符号位
        */
       if(num==0)return "0";
       unsigned n = num;
       string res;
       string hex_char="0123456789abcdef";
       while(n){
         res = hex_char[n & 0xf] + res;
         n = n >> 4;
         cout << n << endl;
       }
       return res;
    }
};

int main(){
  Solution so;
  cout << so.toHex(-1) << endl;
}