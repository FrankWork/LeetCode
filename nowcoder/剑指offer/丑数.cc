#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
      // if(index<1)return index;
      vector<int> res(index);

      int i2=0,i3=0,i5=0;
      int t2,t3,t5;
      res[0]=1;

      for(int i=1;i<index;++i){
        t2=res[i2]*2;
        t3=res[i3]*3;
        t5=res[i5]*5;
        if(t2 <= t3 && t2 <= t5){
          res[i]=t2;i2++;
        }
        if(t3 <= t2 && t3 <= t5){
          res[i]=t3;i3++;
        }
        if(t5 <= t2 && t5 <= t3){
          res[i]=t5;i5++;
        }
      }
      return res[index-1];
    }
};

int main(){
  Solution so;
  for(int i=1;i<10;++i)
  cout << so.GetUglyNumber_Solution(i) << endl;
} 