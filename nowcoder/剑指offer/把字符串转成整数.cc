#include "template.h"

class Solution {
public:
    int StrToInt(string str) {
        int s=0, neg=0;
        int i=0;
        if(str.length()==0) return 0;
        if(str[0]=='-'){
            neg=1;
            i=1;
        }else if(str[0]=='+'){
            i=1;
        }
        for(;i<str.length();++i){
            if(str[i]<'0' || str[i] >'9')return 0;
            s=s*10+str[i]-'0';
        }
        if(neg)s= -s;
        return s;
    }
};



int main(){
Solution so;
    
cout << so.StrToInt("+2147483647")<<endl;
cout << so.StrToInt("1a33")<<endl;

}