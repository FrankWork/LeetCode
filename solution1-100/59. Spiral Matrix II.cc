#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> matrix(n, vector<int>(n));
      int num=0;
      int r1=0, r2 = n-1;
      int c1=0, c2 = n-1;

      while(r2>=r1 && c2>=c1){
        for(int i=c1;i<=c2;++i){
          matrix[r1][i]=++num;
        }
        for(int i=r1+1;i<=r2;++i){
          matrix[i][c2]=++num;
        }
        for(int i=c2-1;i>=c1;--i){
          matrix[r2][i]=++num;
        }
        for(int i=r2-1;i>=r1+1;--i){
          matrix[i][c1]=++num;
        }
        ++r1;
        --r2;
        ++c1;
        --c2;
      }
      
      return matrix;
    }
};

int main(){
  Solution so;
  vector<vector<int>> matrix = so.generateMatrix(3);
  
  for(auto vec: matrix){
    for(int i:vec){
      cout << i << " ";
    }
    cout <<'\n';
  }
  return 0;
}