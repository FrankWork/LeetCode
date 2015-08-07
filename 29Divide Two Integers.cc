/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

Hide Tags Math Binary Search

*/

#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!dividend || !divisor)return 0;

        bool pstv=true;//positive
        if((dividend<0&&divisor>=0) || (dividend>=0&&divisor<0)) pstv=false;


        long long x = dividend; x=x>0?x:-x;
        long long y = divisor;  y=y>0?y:-y;
        long long ans = 0,ty=y;
        int cnt =1;

        if(x==y)ans = 1;
        else if(y==1)ans = x;
        else
            while(x>ty){
cout <<"0 x:"<<x<< ", y:"<<y<<endl;
               if(x-(y<<1) >= 0){//y*2;
                 y=y<<1;
cout <<"1 x:"<<x<< ", y:"<<y<<endl;
                 x-=y;
                 cnt=cnt<<1;
                 ans+=cnt;
               }else if(x-y >= 0){//y
cout <<"2 x:"<<x<< ", y:"<<y<<endl;
                 x-=y;
                 ans+=cnt;
               }else if(x-(y>>1) >= 0){// y/2
                   y=y>>1;
cout <<"3 x:"<<x<< ", y:"<<y<<endl;
                   x-=y;
                   cnt=cnt>>1;
                   ans+=cnt;
               }else{
                   if(y<0)break;
                    y=y>>1;
cout <<"4 x:"<<x<< ", y:"<<y<<endl;
                    cnt=cnt>>1;
               }
            }
        if(ans>INT_MAX) return pstv?INT_MAX:INT_MIN;
        return pstv?ans:-ans;
    }
};

int main(){
    Solution so;
    //cout <<2147483647/ 2<<","<<endl;
    //cout<<so.divide(2147483647, 2)<<endl;

    cout <<-1010369383/ -2147483648<<","<<endl;
    cout<<so.divide(-1010369383, -2147483648)<<endl;

    cout <<-2147483648/ -1<<","<<endl;
    cout<<so.divide(-2147483648, -1)<<endl;


    return 0;
}
