#include "template.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        /* 以运算符为界，将字符串分为左右两部分，分别求值
          左部分求值结果有很多个，右部分求值结果有很多个
          左右部分的结果要遍历一遍
        */
      //  cout<<s<<endl;
       vector<int> res;
      
       for(int i=0;i<s.length();++i){
         if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
          //  cout<<s[i]<<endl;
           vector<int> left = diffWaysToCompute(s.substr(0, i));
           vector<int> right = diffWaysToCompute(s.substr(i+1));


           for(int a:left){
             for(int b:right){
               switch(s[i]){
                 case '+': res.push_back(a+b);break;
                 case '-': res.push_back(a-b);break;
                 case '*': res.push_back(a*b);break;
               }
             }
           }


         }
         
       }
       if(res.empty()) {
         res.push_back(stoi(s));
         return res;
       }
      return res;
    }
};


int main(){
  Solution so;
  // {}
  vector<int> a = so.diffWaysToCompute("2-1-1");
  print(a);

  
}