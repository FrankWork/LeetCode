#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      int m = matrix.size()-1; // index of rows
      if(m<0){return res;}
      int n = matrix[0].size()-1;// index of cols
      int c=0;// number of circles

      while(m+1>2*c && n+1>2*c){
        cout << m << " rows " << n << " columns" << endl;
        //to right
        for(int i=c;i<=n-c;++i){
          cout << "to right " << i << endl;
          res.push_back(matrix[c][i]);
        }
        // to down
        for(int i=c+1;i<=m-c;++i){
          cout << "to down " << i << endl;
          res.push_back(matrix[i][n-c]);
        }
        // to left
        for(int i=n-c-1;i>=c&&m-c>c;--i){
          cout << "to left " << i << endl;
          res.push_back(matrix[m-c][i]);
        }
        // to up
        for(int i=m-c-1;i>=c+1&&n-c>c;--i){
          cout << "to up " << i << endl;
          res.push_back(matrix[i][c]);
        }
        // m-=2;
        // n-=2;
        ++c;
      }
      
      
      return res;
    }
};

int main(){
  Solution so;
  vector<vector<int>> matrix
  // {
  //   {7,9,6}
  // };

  // {
  //   {7},{9}, {6}
  // };
  
  // {
  //   {2,3}
  // };

  {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
  };

  // {
  //   { 1, 2, 3, -1, 11 },
  //   { 4, 5, 6,-2, 12 },
  //   { 7, 8, 9,-3, 13 },
  // };

  // {
  //   { 1, 2, 3, -1, 11 },
  //   { 4, 5, 6,-2, 12 },
  //   { 7, 8, 9,-3, 13 },
  //   {21, 22, 23, 24, 25}
  // };


  vector<int> res = so.spiralOrder(matrix);
  for(auto i: res){
    cout << i << " ";
  }
  return 0;
}