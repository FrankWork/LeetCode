#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      int i=0,j=0;
      bool res=false;

      while(i<s.size() && j<p.size()){
        if(s[i]==p[j]){
          i++;
          j++;
        }else{
          i++;
          j=0;
        }
      }
      if(i==s.size() && j==p.size()){res=true;}
      
      return res;
    }
};

void print(bool value){
  cout << (value?"true":"false") << endl;
}
int main(){
  Solution so;
  print(so.isMatch("aa","a")      );  // false
  print(so.isMatch("aa","aa")     );  // true
  print(so.isMatch("aaa","aa")    );  // false
  print(so.isMatch("aa", "*")     );  // true
  print(so.isMatch("aa", "a*")    );  // true
  print(so.isMatch("ab", "?*")    );  // true
  print(so.isMatch("aab", "c*a*b"));  // false
}