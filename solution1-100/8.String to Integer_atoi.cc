/**
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.




Solution:
To deal with overflow, inspect the current number before multiplication. If the current number is greater than 214748364, we know it is going to overflow. On the other hand, if the current number is equal to 214748364, we know that it will overflow only when the current digit is greater than or equal to 8.
*/
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int num=0;
        bool posi = true;
        int index=0;
        while(isspace(str[index]))
            index++;
        if(str[index]=='-')
        {
            posi=false;
            index++;
        }else if(str[index]=='+')
        {
            index++;

        }

        for(;index<str.length();++index)
        {
            int t = str[index];
            if(t>='0' && t <='9')
            {

                if(posi)
                {
                    if(num <= INT_MAX/10)
                    {
                        num = num*10;

                    }else
                    {
                        num = INT_MAX;
                        break;
                    }
                    t = t-'0';
                     if(t <= INT_MAX-num)
                    {
                        num+=t;
                    }else
                    {
                        num = INT_MAX;
                        break;
                    }
                }else{
                    if(num >= INT_MIN/10)
                    {
                        num = num*10;
                    }else
                    {
                        num = INT_MIN;
                        break;
                    }
                    t = t-'0';
                    t=-t;

                    if(t >= INT_MIN-num)
                    {
                       num+=t;
                    }else
                    {
                        num = INT_MIN;
                        break;
                    }
                }


            }else
            {
                break;
            }

        }
        return num;
    }
};
void test(string str)
{
    Solution so;
    cout << so.myAtoi(str) <<" :" << atoi(str.c_str())<< endl;
}
int main()
{
    test("120");
    test(" \n\t120");
    test(" 0120 ");
    test(" 0120abc");
    test("ab0120 ");
    test(" 01a20abc");

    test("-120");
    test("- \n\t120");
    test("- 0120 ");
    test("- 0120abc");
    test("-ab0120 ");
    test("- 01a20abc");

    test("-0");
    test("-120");
    test("0");
    test("0.0");

    test("+0");
    test("+120");
    test("+");
    test("+0.0");

    test("-+1");
    test("+-1");

    test("2147483648");
    test("2147483647");

    test("-2147483648");
    test("-2147483647");
    test("-2147483649");

    test("-1");
    test("1");
    test("-120");
    test("120");

    return 0;
}

