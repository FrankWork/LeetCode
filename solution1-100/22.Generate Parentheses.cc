/*
Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Hide Tags Backtracking String
Hide Similar Problems (M) Letter Combinations of a Phone Number (E) Valid Parentheses

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        num = n*2;
        ln=rn=n;
        stk.push('#');

        backtrack(0);
        return vs;
    }
private:
    void backtrack(int n){
        if(n==num){
            if(stk.top()=='#')
                vs.push_back(s);
            return;
        }

        //the n-th char is (
        if(ln>0){
            --ln;
            s+='(';
            stk.push('(');
            backtrack(n+1);
            stk.pop();
            s=s.substr(0,s.length()-1);
            ++ln;
        }
        //the n-th char is )
        if(rn>0){
            --rn;
            s+=')';
            bool pushed = false;
            if(stk.top()=='('){
                stk.pop();
            }else{
                stk.push(')');
                pushed=true;
            }
            backtrack(n+1);
            if(pushed){
                stk.pop();
            }else{
                stk.push('(');
            }
            s=s.substr(0, s.length()-1);
            ++rn;
        }
    }
    string s;
    int num;// num of chars
    int ln;//  num of left Parenthesis
    int rn;//  num of right Parenthesis
    vector<string> vs;
    stack<char> stk;
};

int main(){
    Solution so;
    vector<string> vs = so.generateParenthesis(3);

    for(string s: vs)
        cout<<s<<endl;
    return 0;
}
