/**
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321


To check for overflow/underflow, we could check if ret > 214748364 or ret < ¨C214748364 before multiplying by 10. On the other hand, we do not need to check if ret == 214748364, why?
*/
#include <iostream>
#include<limits>
//using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool pos = true;
        int im = INT_MAX/10;
        if(x<0)
        {
            pos = false;
            x=-x;
        }
        int ret=0;
        while(x)
        {
            int t=x%10;
            x/=10;
            if(ret > im)
                return  0;
            ret *=10;
            int r = INT_MAX-ret;
            if(t>r)
                return 0;
            ret += t;
        }

        return pos?ret:-ret;
    }
};

int main()
{
    Solution so;
      std::cout <<INT_MAX<<std::endl;///2147483647 2**31-1
      /*cout <<so.reverse(10)<<endl;
    cout <<so.reverse(-1)<<endl;
    cout << so.reverse(1534236469)<<endl;
   cout << so.reverse(9646324351)<<endl;
    cout << so.reverse(2147483647)<<endl;
    cout << so.reverse(1000000003)<<endl;

x:1534236469
9
96
964
9646
96463
964632
9646324
96463243
964632435
1056389759
1056389759

Process returned 0 (0x0)   execution time : 0.036 s
Press any key to continue.

    */

    return 0;
}
