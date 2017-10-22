#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& b, int si, int bj){
      int i=si,j=bj;
      bool res=true;

      while(i<s.size() && j<p.size()){
        if(s[i]==p[j] || p[j]=='?'){//|| p[j]=='*'
          i++;
          j++;
        }
        else if(p[j]=='*'){

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
      if(i!=s.size() || j!=p.size()){res=false;}
      
      return res;
    }
    bool isMatch(string s, string p) {
      return isMatch(s, p, 0, 0);
    }
};

void print(bool value, bool expect){
  cout << (value?"true":"false") << " " << (expect?"true":"false") << endl;
}
int main(){
  Solution so;
  // print(so.isMatch("aa","a")      , false); 
  // print(so.isMatch("aa","aa")     , true); 
  // print(so.isMatch("aaa","aa")    , false); 
  // print(so.isMatch("aaa","")    , false);   
  // print(so.isMatch("abc","abc")    , true); 
  // print(so.isMatch("aaa","a?a")    , true); 
  // print(so.isMatch("ada","a?a")    , true); 

  print(so.isMatch("aa", "*")     , true); 
  // print(so.isMatch("aa", "a*")    , true); 
  // print(so.isMatch("ab", "?*")    , true); 
  // print(so.isMatch("aab", "c*a*b"), false); 
}