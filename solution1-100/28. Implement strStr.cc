/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.

Hide Tags Two Pointers String

*/

#include <iostream>
using namespace std;

class Solution {
public:

    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();
        int i,j;

        for(i=0,j=0;i<n1 && j < n2;i++){
            if(haystack[i]!=needle[j]){
                i-=j;
                j=0;
            }else{j++;}
        }

        return j==n2?i-j:-1;
    }
};

int main(){
    Solution so;
    cout << so.strStr("ababcd","abc");
    return 0;
}
