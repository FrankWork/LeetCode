#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      int i=0,j=0;
      bool res=true;

      while(i<s.size() && j<p.size()){
        if(s[i]==p[j] || p[j]=='?'){//|| p[j]=='*'
          i++;
          j++;
        }else if(p[j]=='*'){
          if(j<p.size()-1 && s[i]!=p[j+1]){
            i++;
          }else{
            j++;
          }
        }
        else{
          res=false;
          break;
        }
      }
      
      return res;
    }
};

void print(bool value, bool expect){
  cout << (value?"true":"false") << " " << (expect?"true":"false") << endl;
}
int main(){
  Solution so;
  print(so.isMatch("aa","a")      , false); 
  print(so.isMatch("aa","aa")     , true); 
  print(so.isMatch("aaa","aa")    , false); 
  print(so.isMatch("aa", "*")     , true); 
  print(so.isMatch("aa", "a*")    , true); 
  print(so.isMatch("ab", "?*")    , true); 
  print(so.isMatch("aab", "c*a*b"), false); 
}