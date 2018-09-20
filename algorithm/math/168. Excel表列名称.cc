#include "../template.h"

class Solution {
public:
    string convertToTitle(int n) {
        /*
          转换为26进制，辗转相除法
        */
       string res;
       string chars="ABCDEFGHIJKLMNOPKRSTUVWXYZ";
       int r;
       
       while(n){
         r = n%26;
         if(r==0) {
           res = "Z"+res;
           n--;
         }
         else res = chars[r-1] + res;
         n/=26;
       }
       return res;
    }
};

int main(){
  Solution so;
  cout << so.convertToTitle(1)<<endl;//A    1除以26，商0余1   1
  cout << so.convertToTitle(2)<<endl;//B    2除以26，商0余2   2
  cout << so.convertToTitle(26)<<endl;//Z   26除以26，商1余0; 1除以26，商0余1  10

  cout << so.convertToTitle(27)<<endl;//AA  27除以26，商1余1；1除以26，商0余1  11
  cout << so.convertToTitle(28)<<endl;//AB  28除以26，商1余2；1除以26，商0余1  12
  cout << so.convertToTitle(701)<<endl;//ZY
  
  
}