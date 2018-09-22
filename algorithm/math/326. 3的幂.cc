#include "../template.h"


class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=1;
        while(i<n && n%3==0){
          i*=3;
        }
        return n==i;
    }
};

int main(){
  Solution so;
  cout << so.isPowerOfThree(1) << endl;
  cout << so.isPowerOfThree(27) << endl;
  
  cout << so.isPowerOfThree(2147483647) << endl;
}
