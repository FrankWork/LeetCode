/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid
but "(]" and "([)]" are not.

Hide Tags Stack String

*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)return true;
        stack<char> stk;
        stk.push('#');
        char c,t;

        for(int i=0;i<s.length();i++){
            c = s[i];
            t = stk.top();
            if((t=='(' &&c==')') || (t=='['&&c==']') || (t=='{' && c=='}') )
                stk.pop();
            else
                stk.push(c);
        }
        return stk.top()=='#';
    }
};

int main(){
    Solution so;
    cout<<so.isValid("([]")<<endl;
    return 0;
}

