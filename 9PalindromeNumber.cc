/**
Determine whether an integer is a palindrome. Do this without extra space.


*/
#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int t=x,y=0;
        while(t)
        {
            y= y*10+t%10;
            t/=10;
        }
        return x==y;
    }

};

int main()
{
    /**
0-9
11
22
33
aa

a...a

a<<1

    */
    Solution so;
    cout << so.isPalindrome(123)<<endl;
    cout << so.isPalindrome(-123)<<endl;

    cout << so.isPalindrome(121)<<endl;
    cout << so.isPalindrome(-121)<<endl;
    cout << so.isPalindrome(-21474 47412)<<endl;
    ///
    return 0;
}
