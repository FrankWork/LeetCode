#include "template.h"

class Solution {
public:
    int Sum_Solution(int n) {
      int sum=n;
      (n>0)&& (sum+=Sum_Solution(n-1));
      return sum;
    } 
};

int main(){
Solution so;
cout <<so.Sum_Solution(100)<<endl;

}