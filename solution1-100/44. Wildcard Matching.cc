#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;
      for(i=0,j=0 ; i<slen; ++i, ++j)
      {
          if(p[j]=='*')
          { //meet a new '*', update traceback i/j info
              iStar = i;
              jStar = j;
              --i;
          }
          else
          { 
              if(p[j]!=s[i] && p[j]!='?')
              {  // mismatch happens
                  if(iStar >=0)
                  { // met a '*' before, then do traceback
                      i = iStar++;
                      j = jStar;
                  }
                  else return false; // otherwise fail
              }
          }
      }
      while(p[j]=='*') ++j;
      return j==plen;
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
  print(so.isMatch("aaa","")    , false);   
  print(so.isMatch("abc","abc")    , true); 
  print(so.isMatch("aaa","a?a")    , true); 
  print(so.isMatch("ada","a?a")    , true); 

  print(so.isMatch("aa", "aa*")    , true); 
  print(so.isMatch("aa", "*")     , true); 
  print(so.isMatch("aa", "a*")    , true); 
  print(so.isMatch("ab", "?*")    , true); 
  print(so.isMatch("aab", "c*a*b"), false); 
  print(so.isMatch("abc.out", "*.out"), true); 
  print(so.isMatch("abc.out", "*.out*"), true); 

  // 10s
  print(so.isMatch("bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab", "b*b*ab**ba*b**b***bba"), false); 
  
  
}