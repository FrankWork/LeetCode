#include "template.h"

class Solution {
public:
    bool isSubsequence(string &s, string &t) {
        /* 
           s(i)==t(j) i递增，j递增
           否则        j递增

           i==len(s)  匹配成功
        */
       int i=0,j=0;
       while(i<s.size() && j<t.size()){
         if(s[i]==t[j]){
           ++i;
         }
         ++j;
       }
       return i==s.size();
    }
};

int main(){

}