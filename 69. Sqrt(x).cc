#include <iostream>

using namespace std;


class Solution {
public:
    
    int mySqrt(int x) {
      if(x==0) return 0;
      int l=1, r=x, m;
      while(l<=r){
        m = (l+r)/2;
        if(m==x/m){
          return m;
        }else if(m>x/m){
          r=m-1;
        }else if(m<x/m){
          l=m+1;
        }
      }
      return r;
    }
};


int main()
{
  Solution so;
  for(int i=0;i<=20;++i){
    cout << i << " " << so.mySqrt(i) << endl;
  }
  cout << so.mySqrt(2147483647) << endl;

}