#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
      int cur,high,low;
      int res=0;
      int i=1;
      while(n/i!=0){
        low = n%i;
        cur = n/i%10;
        high = n/(i*10);
        
        // printf("%d %d %d\n", high, low, cur);
        if(cur==0){
          res+=high*i;
        }else if(cur==1){
          res+=high*i+low+1;
        }else{
          res+=(high+1)*i;
        }
        i*=10;
      }
      return res;
    }
};

int main(){
  Solution so;
  int n = so.NumberOf1Between1AndN_Solution(13);
  cout<<n<<endl;
}