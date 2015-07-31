/**
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

solution: backtracking
解空间：        p所能表示的所有字符串集合
解空间的结构：  字符串

具体解法：
下一个字符是'*', 匹配0,1,2,3....个字符
下一个字符不是'*'，匹配当前字符

*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return  backtrack(s,p,0,0);
    }
    ///"aab","c*a*ab"
    bool backtrack(const string&s, const string &p,int si,int pi){
       if(pi==p.length()){
            return si==s.length();//true or false;
        }
       //next char is NOT '*'
       if(p[pi+1]!='*'){
            if(p[pi]=='.'||p[pi]==s[si]){
                return backtrack(s,p,si+1,pi+1);
            }
            else return false;
       }
       //next char is '*'
       while(si<=s.length() && (p[pi]==s[si]||p[pi]=='.')){//*matches zero, one,two,three,......char
        if(backtrack(s,p,si++,pi+2))
            return true;
        //else continue;
       }
       return backtrack(s,p,si++,pi+2);//
    }
};

int main()
{
    Solution so;

    cout <<so.isMatch("bbbba",".*a*a")<<endl;//→ true
    cout <<so.isMatch("aa","a")<<endl;//→ false
    cout <<so.isMatch("a","aa")<<endl;//→ false
    cout <<so.isMatch("aa","aa")<<endl;//→ true
    cout <<so.isMatch("aaa","aa")<<endl;// → false

    cout <<so.isMatch("aa", ".*")<<endl;// true
    cout <<so.isMatch("ab", ".*")<<endl;// true

   // cout <<so.isMatch("aab", "c*a*ab")<<endl;// true
   // cout <<so.isMatch("abcdabab","ab.*ab")<<endl;//true

   //cout <<so.isMatch("abcdefghijklmb","a*b*c*d*e*f*g*h*i*j*c")<<endl;//false
    //cout <<so.isMatch("aaaaaaaaaaaaab","a*a*a*a*a*a*a*a*a*a*b")<<endl;//true
    //cout <<so.isMatch("aaaaaaaaaaaaab","a*a*a*a*a*a*a*a*a*a*c")<<endl;//false
    //cout <<so.isMatch("acaabbaccbbacaabbbb","a*.*b*.*a*aa*a*")<<endl;//false

    return 0;
}
