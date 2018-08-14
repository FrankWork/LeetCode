#include "template.h"

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
      vector<int> b(A.size(), 1);

      //从对角线分为上三角和下三角，对角线为1
      int t=1;
      //下三角
      for(int i=0;i<A.size()-1;++i){
        t *= A[i];
        b[i+1]=t;
      }
      t=1;
      //上三角
      for(int i=A.size()-1;i>0;--i){
        t*=A[i];
        b[i-1]*=t;
      }
      return b;
    }
};

int main(){
  vector<int> nums{1,2,3,4,5};
  Solution so;
  auto b=so.multiply(nums);
  print(b);
}