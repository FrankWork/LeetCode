#include "template.h"

class Solution {
public:
    int rectCover(int n) {
        /* f(i) i个2*1的小矩形覆盖2*i的大矩形的方法数
               竖着放    横着放
        f(i) = f(i-1) + f(i-2)
               0    i=0
               1    i=1
               2    i=2
               3    i=3
        */
       if(n==0)return 0;
       if(n==1)return 1;
       if(n==2)return 2;

       int n1=1, n2=2, res;
       for(int i=2;i<n;++i){
           res=n1+n2;
           n1=n2;
           n2=res;
       }
       return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    cout << so.rectCover(3)<<endl;
    cout << so.rectCover(4)<<endl;

    return 0;
}
