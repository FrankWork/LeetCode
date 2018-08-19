#include "template.h"

class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        int l=0, r=n-1;
        while(l<r){
            bool bl = s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u' ||
                        s[l]=='A' || s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U';
            bool br = s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'||
                        s[r]=='A' || s[r]=='E' || s[r]=='I' || s[r]=='O' || s[r]=='U';
            
            if(bl && br){
                swap(s[l], s[r]);
                l++;r--;
            }
            else if(bl){r--;}
            else{l++;}
        }
        return s;
    }
};

int main(){
    string s="hello";
    Solution so;
    cout <<so.reverseVowels(s)<<endl;
}
