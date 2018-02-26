#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
      // remove leading and tailing space
      int left=0, right=s.length()-1;
      while(isspace(s[left]) && left<=right){
        ++left;
      }
      while(isspace(s[right]) && left<=right){
        --right;
      }

      // // print
      // cout << "input: ";
      // for(int i=left;i<=right;++i){
      //   cout << s[i];
      // }
      // cout << "\n";
      
      int state=0;// 0 start, 1 integer, 2 decimal, 3 exp, 
                  // 4 ., 5 e/E, 6 +/- after 0, 7 +/1 after 5

      if(left > right){
        return false;// empty string
      }

      for(int i=left;i<=right;++i){
        switch(state){
          case 0:{
            // cout << "state: " << state << "\n";
            if(isdigit(s[i])){
              state=1;
            }else if(s[i]=='.'){
              state=4;
            }else if(s[i]=='+' || s[i]=='-'){
              state=6;
            }else{
              return false;
            }
            break;
          }
          case 1:{
            // cout << "state: " << state << "\n";
            if(s[i]=='.'){
              state=2;
            }else if(s[i]=='e' || s[i]=='E'){
              state=5;
            }else if(!isdigit(s[i])){
              return false;
            }
            break;
          }
          case 2:{
            // cout << "state: " << state << "\n";
            if(s[i]=='e' || s[i]=='E'){
              state=5;
            }else if(!isdigit(s[i])){
              return false;
            }
            break;
          }
          case 3:{
            // cout << "state: " << state << "\n";
            if(!isdigit(s[i])){
              return false;
            }
            break;
          }
          case 4:{
            // cout << "state: " << state << "\n";
            if(isdigit(s[i])){
              state=2;
            }else{
              return false;
            }
            break;
          }
          case 5:{
            // cout << "state: " << state << "\n";
            if(isdigit(s[i])){
              state=3;
            }else if(s[i]=='+' || s[i]=='-'){
              state=7;
            }else{
              return false;
            }
            break;
          }
          case 6:{
            // cout << "state: " << state << "\n";
            if(isdigit(s[i])){
              state=1;
            }else if(s[i]=='.'){
              state=4;
            }else{
              return false;
            }
            break;
          }
          case 7:{
            // cout << "state: " << state << "\n";
            if(isdigit(s[i])){
              state=3;
            }else{
              return false;
            }
            break;
          }

        }
      }

      if(state==4 || state==5 || state==6 || state==7){
        return false;
      }
      
      return true;
    }
};

int main(){
  Solution so;
  // cout << so.isNumber("  ") << endl;    // false
  // cout << so.isNumber(".") << endl;     // false
  // cout << so.isNumber(" 123 ") << endl; // true
  // cout << so.isNumber("0") << endl;     // true
  // cout << so.isNumber(" 0.1 ") << endl; // true
  // cout << so.isNumber("abc") << endl;   // false
  // cout << so.isNumber("1 a") << endl;   // false
  // cout << so.isNumber("2e10") << endl;  // true
  // cout << so.isNumber("3.") << endl;  // true
  // cout << so.isNumber("-1.") << endl;  // true
  cout << so.isNumber("+.8") << endl;  // true
}