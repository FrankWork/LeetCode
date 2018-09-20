#include "../template.h"

class Solution {
public:
    int countPrimes(int n) {
        /* 质数：因子只有1和n的数
           用筛选法：每找到一个质数，就将能被该质数整除的数去掉
           1 2 3 4 5 6 7 8 9 10
           0 1 1 0 1 0 1 0 1 0
        */
       vector<bool> primes(n, true);
       int res=0;
       for(int i=2;i<n;++i){
        //  printf("%d\n", i);
         if(!primes[i])continue;
         res++;

         // 从 i * i 开始，因为如果 k < i，那么 k * i 在之前就已经被去除过了
         for(unsigned long j=(unsigned long)i*i;j<n;j+=i){
           primes[j]=false;
         }
         
       }
      //  print(primes);
       return res;
    }
};

int main(){
  Solution so;
  cout << so.countPrimes(10) << endl;
  cout << so.countPrimes(499979) << endl;//41537
  cout << so.countPrimes(999983) << endl;
  
  
  
}