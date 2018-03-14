#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();

      vector<int> rows(m, 0);
      vector<int> cols(n, 0);

      for(int r=0;r<m;++r){
        for(int c=0;c<n;++c){
          if(matrix[r][c]==0){
            if(rows[r]==0) rows[r] = 1;
            if(cols[c]==0) cols[c] = 1;
          }
        }
      }

      for(int r=0;r<m;++r){
        if(rows[r]==1){
          for(int c=0;c<n;++c){
            matrix[r][c]=0;
          }
        }
      }
      for(int c=0;c<n;++c){
        if(cols[c]==1){
          for(int r=0;r<m;++r){
            matrix[r][c]=0;
          }
        }
      }
      
    }
};


int main(){
  
}