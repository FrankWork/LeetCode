#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
      int n=0;
      int i = s.length()-1;
      while(s[i]==' ')
        --i;
      for(; i>=0; --i){
        if(s[i] != ' '){
          ++n;
        }else{
          return n;
        }
      }
      return n;
    }
};

int main(){
  Solution so;

  cout << so.lengthOfLastWord("Hello World") << endl;
  cout << so.lengthOfLastWord("a") << endl;
  cout << so.lengthOfLastWord("a ") << endl;
}
