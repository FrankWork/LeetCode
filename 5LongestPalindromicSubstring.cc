/**
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int st=0,e=0,len=0;
        for(int i=0;i<s.length();++i){
            int j=0;
            int s1=i,e1 = i;
            while(i-j>=0 &&i+j<s.length()){
                if(s[i-j]==s[i+j]){
                    s1=i-j;
                    ///012
                    ///aba
                    e1=i+j;
                    j++;
                }else{
                    break;
                }
            }
            j=0;
            int s2=i,e2=i;
            while(i-j>=0 &&i+1+j<s.length()){
                ///abba
                if(s[i-j]==s[i+1+j]){
                    s2=i-j;
                    e2=i+1+j;
                    j++;
                }else{
                    break;
                }
            }
            if(len < e1-s1+1){
                len = e1-s1+1;
                e = e1;
                st=s1;
            }
            if(len < e2-s2+1){
                len = e2-s2+1;
                e = e2;
                st=s2;
            }

        }
        return s.substr(st,e-st+1);
    }
};
int main()
{
    Solution so ;
    string s ="cabbad";
    cout <<so.longestPalindrome(s)<<endl;

    s ="eabad";
    cout <<so.longestPalindrome(s)<<endl;
    return 0;
}
