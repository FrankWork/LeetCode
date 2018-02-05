#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout << nums[i]<<"\t";
  }
  cout << endl;
}
void print2d(vector<vector<int>> res){
  for(int i=0;i<res.size();i++){
    print(res[i]);
  }
  cout << endl;
}

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    // (i,j)       =>   (j,n-1-i)
    //  ^                  |
    //  |                  v
    // (n-1-j,i)  <=   (n-1-i, n-1-j)
    int n = matrix.size();
    int m = n%2==0 ? n/2 : n/2+1;
    int t;
    for(int i=0;i<m;i++){
      for(int j=i;j<n-1-i;j++){
        t = matrix[i][j];
        matrix[i][j]=matrix[n-1-j][i];
        matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
        matrix[j][n-1-i]=t;
      }
    }
  }
};



int main(){
  Solution so;

  vector<vector<int>> matrix{
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  so.rotate(matrix);
  print2d(matrix);
  //   [7,4,1],
  //   [8,5,2],
  //   [9,6,3]

  vector<vector<int>> matrix2{
    { 5, 1, 9,11},
    { 2, 4, 8,10},
    {13, 3, 6, 7},
    {15,14,12,16}
  };
  so.rotate(matrix2);
  print2d(matrix2);
  //   [15,13, 2, 5],
  //   [14, 3, 4, 1],
  //   [12, 6, 8, 9],
  //   [16, 7,10,11]

 
}