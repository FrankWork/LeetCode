#include "template.h"

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<bool> used(rows*cols, false);
        return bt(threshold, used, rows, cols, 0, 0);
    }
    int bt(int threshold, vector<bool>&used, int rows, int cols, int i, int j){
      if(i<0||i>=rows || j<0||j>=cols || used[i*cols+j] || !valid(i,j,threshold))
          return 0;
      used[i*cols+j]=true;//不需要重新置false
      return bt(threshold, used, rows, cols, i-1, j) +
             bt(threshold, used, rows, cols, i+1, j) + 
             bt(threshold, used, rows, cols, i, j-1) +
             bt(threshold, used, rows, cols, i, j+1) + 1;
    }
    int sumof(int i){
      int sum=0;
      while(i){
        sum+=i%10;
        i/=10;
      }
      return sum;
    }
    bool valid(int i, int j, int threshold){
      return sumof(i)+sumof(j)<=threshold;
    }
};

int main(){

}