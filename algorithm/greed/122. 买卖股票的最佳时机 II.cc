#include "template.h"

class Solution {
public:
    int maxProfit(vector<int>& a) {
        /*
             [a, b, c, d]，如果有 a <= b <= c <= d ，那么最大收益为 d - a。
             而 d - a = (d - c) + (c - b) + (b - a)
        */
       int res=0, n=a.size();
       for(int i=1;i<n;++i){
         if(a[i]>a[i-1])
            res += a[i]-a[i-1];
       }
       return res;
    }
};

int main(){

}