#include "template.h"

class Solution {
public:
    bool isNumeric(char* str)
    {
        char * start = str;
        bool sign=false, decimal=false, hasE=false;
        while(*str!='\0'){
          if(*str=='e' || *str=='E'){
            if(*(str+1)=='\0' )return false;// e后面不为空
            if(hasE)return false;
            hasE=true;
          }else if(*str=='+' || *str=='-'){
            // 第二次出现+-符号，则必须紧接在e之后
            if(sign && *(str-1)!='e' && *(str-1)!='E') return false;
            // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
            if(!sign && *(str-1)!='e' && *(str-1)!='E' && str!=start) return false;
            sign=true;
          }else if(*str=='.'){
            // e后面不能接小数点，小数点不能出现两次
            if(hasE || decimal) return false;
            decimal=true;
          }else if(*str<'0' || *str>'9')
            return false;
          
          str++;
        }
        return true;
    }
    
};

int main(){
  Solution so;
  cout <<so.isNumeric((char*)"123.45e+6")<<endl;
}