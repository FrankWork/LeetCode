#include "template.h"

class Solution {
public:
    bool validPalindrome(string &s) {
        /* 若在 l, r两个位置不构成回文，继续验证 s[l+1, r], s[l, r-1]
        */
        int n=s.length();
        int c=0;

        int l=0,r=n-1;

        while(l<=r){
            if(s[l]==s[r]){
                l++;r--;
            }else{
                return isPalindrome(s,l+1, r) || isPalindrome(s, l, r-1);
            }
        }

        return true;
    }

    bool isPalindrome(string& s, int l, int r){
        while(l<=r){
            if(s[l]==s[r]){
                l++;r--;
            }else return false;
        }
        return true;
    }
};