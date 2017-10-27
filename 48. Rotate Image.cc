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
    // (i,j)=>(j,n-1-i)
    int n = matrix.size();
    vector<vector<int>> copy;
    for(int i=0;i<n;i++){
      copy.push_back(matrix[i]);
    }
    
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        swap(copy[i][j], matrix[j][n-1-i]);
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