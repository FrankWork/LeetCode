#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int m = matrix.size(); // rows
      int n = matrix[0].size();// cols
      vector<int> res;
      int r=0, c=0;
      // number of circles
      for(int i=0;;++i){
        while(c<n-i){
          res.push_back(matrix[r][c]);
          c+=1;
        }
        while(r<m-i){
          res.push_back(matrix[r][c]);
          r+=1;
        }
        while(c>i){
          res.push_back(matrix[r][c]);
          c-=1;
        }
        while(r>i){
          res.push_back(matrix[r][c]);
          r-=1;
        }
      }
      return res;
    }
};

int main(){
  Solution so;
  vector<vector<int>> matrix{
 { 1, 2, 3 },
 { 4, 5, 6 },
 { 7, 8, 9 },
}
;
  vector<int> res = so.spiralOrder(matrix);
  for(auto i: res){
    cout << i << " ";
  }
  return 0;
}