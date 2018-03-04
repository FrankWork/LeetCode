#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      if(m==0)return false;
      int n = matrix[0].size();
      if(n==0)return false;

      int l=0,r=m-1;
      int mid;

      while(l<=r){
        mid = (l+r)/2;
        // cout << "l: "<< l << " r:"<< r<<  " mid: "<< mid << "\n";
        if(matrix[mid][n-1]==target){
          return true;
        }else if(matrix[mid][n-1]<target){
          l=mid+1;
        }else{
          r=mid-1;
        }
      }
      // cout << "l: "<< l << " r:"<< r<<  " mid: "<< mid << "\n";
      

      int row = l;
      if(row>=m)return false;

      l=0, r=n-1;
      while(l<=r){
        mid = (l+r)/2;
        if(matrix[row][mid]==target){
          return true;
        }else if(matrix[row][mid]<target){
          l=mid+1;
        }else{
          r=mid-1;
        }
      }
      // cout << "mid: "<< mid << "\n";
      return false;
    }
};


int main(){
  
  Solution so;
  
  vector<vector<int>> matrix{
    {1,3,5,7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  
  cout << so.searchMatrix(matrix, 10) <<  endl;
  cout << so.searchMatrix(matrix, 50) <<  endl;
  cout << so.searchMatrix(matrix, 51) <<  endl;

  vector<vector<int>> matrix1{
    {1},
  };
  cout << so.searchMatrix(matrix1, 0) <<  endl;
  cout << so.searchMatrix(matrix1, 1) <<  endl;
  cout << so.searchMatrix(matrix1, 2) <<  endl;

}