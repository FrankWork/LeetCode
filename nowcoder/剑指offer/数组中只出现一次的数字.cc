#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      int sum=0, idx=0;
      for(int i=0;i<data.size();++i){
        sum ^= data[i];
      }

      for(idx=0;idx<32;++idx){
        if(sum & (1<<idx) != 0)break;
      }

      for(int i=0;i<data.size();++i){
        if(data[i] & (1<<idx) != 0){
          *num1 ^= data[i];
        }else{
          *num2 ^= data[i];
        }
      }
    }
};

int main(){
  int idx=0;
  printf("%d\n", (1<<2));
}