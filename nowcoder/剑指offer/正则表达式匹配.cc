#include "template.h"

class Solution {
public:
    bool match(char* str, char* pat)
    {
      if(str==NULL || pat==NULL)
        return false;
      if(*str=='\0'){
        if(*pat=='\0' || *(pat+1)=='*'&&*(pat+2)=='\0')
          return true;
        else
          return false;
      }
      if(*pat=='\0')
        return false;
      
      if(*(pat+1)=='*'){
        if(*pat==*str|| *pat=='.')
          //匹配0个字符，匹配多个字符
          return match(str, pat+2) || match(str+1, pat);
        else
          return match(str, pat+2);// 匹配0个字符
      }

      if(*pat==*str|| *pat=='.')
        return match(str+1, pat+1);
      return false;
    }
};


int main(){
  Solution so;
  cout << so.match((char*)"aaa", (char*)"a.a")<<endl;
}