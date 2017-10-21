#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      int i=0,j=0;

      
      return false;
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