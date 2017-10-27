#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    cout << nums[i]<<" ";
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
    
  }
};



int main(){
  Solution so;

  vector<int> nums{1,1,2};
  print2d(so.rotate(nums));
  // Given input matrix = 
  // [
  //   [1,2,3],
  //   [4,5,6],
  //   [7,8,9]
  // ],
  
  // rotate the input matrix in-place such that it becomes:
  // [
  //   [7,4,1],
  //   [8,5,2],
  //   [9,6,3]
  // ]

  vector<int> nums2{3,3,0,3};
  print2d(so.rotate(nums2));
  // Given input matrix =
  // [
  //   [ 5, 1, 9,11],
  //   [ 2, 4, 8,10],
  //   [13, 3, 6, 7],
  //   [15,14,12,16]
  // ], 
  
  // rotate the input matrix in-place such that it becomes:
  // [
  //   [15,13, 2, 5],
  //   [14, 3, 4, 1],
  //   [12, 6, 8, 9],
  //   [16, 7,10,11]
  // ]

 
}