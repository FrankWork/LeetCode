#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print(vector<int>& nums, int n){
  for(int i=0;i <= n;++i){
    cout << nums[i] << " ";
  }
  cout << endl;
}

class Solution {
public:
    int longestValidParentheses(string s) {
      vector<int> stack; // to store the index of s
      int idx = -1;// top stack index

      // index of invalid '(' or ')' stay in stack
      for(int i=0;i<s.size();i++){
        idx = stack.size()-1;
        if(idx>-1 && s[ stack[idx] ]=='(' && s[i]==')'){
          stack.pop_back();
        }else{
          stack.push_back(i);
        }
      }

      // push s.size() into stack
      stack.push_back(s.size());
      
      int longest = stack[0];// longest valid length
      int n = 0;// valid length

      for(int i=0;i<stack.size()-1;i++){
        n = stack[i+1] - stack[i] - 1;
        if(longest < n){
          longest = n;
        }
      }
      
      return longest;
    }
};

void test(Solution &so, string s, int ans){
  int n = so.longestValidParentheses(s);
  if(n==ans){
    cout << s << "\t" << n << endl;
  }else{
    cout << s << "\t" << n << "\t ans=" << ans << endl;
  }
}
int main(){
  Solution so;
  test(so, "(()", 2);
  test(so, ")()())", 4);
  test(so, "()", 2);
  test(so, "(())", 4);
  test(so, "()(()", 2);
}