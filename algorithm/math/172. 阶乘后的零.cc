#include "../template.h"

class Solution {
public:
    int trailingZeroes(int n) {
        /*
          尾部的 0 由 2 * 5 得来，2 的数量明显多于 5 的数量，因此只要统计有多少个 5 即可。
          对于一个数 N, 包含5的数有：5的倍数，5^2的倍数，5^3的倍数
                                 包含1个5，包含2个5，包含3个5
          N/5: 数N中包含几个5的倍数
          N/5^2: 数N中包含几个5^2的倍数
          

          算法复杂度 O(logn)
        */
       int res=0;
      //  for(int i=5;i<=n;i+=5){
      //    int t=i;
      //    while(t%5==0){
      //      printf("%d %d\n", t, i);
      //      res++;
      //      t/=5;
      //    }
      //  }
      while(n){
        // printf("%d %d\n", n, n/5);
        res += n/5;
        n/=5;
      }
       return res;
    }
};

int main(){
  Solution so;
  // cout << so.trailingZeroes(3)<<endl;//0
  // cout << so.trailingZeroes(5)<<endl;//1
  // cout << so.trailingZeroes(30)<<endl;//7
  // cout << so.trailingZeroes(200)<<endl;//49
  cout << so.trailingZeroes(2147483647)<<endl;//
  
  
  
  
}