#include "template.h"

class Solution {
public:
    int Add(int n1, int n2)
    {
      if(n2==0)return n1;
      return Add(n1^n2, (n1&n2)<<1);
    }
};

int main(){

}