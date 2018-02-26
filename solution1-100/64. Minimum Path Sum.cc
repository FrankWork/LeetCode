#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &path){
    for(auto vec: path){
        for(int i: vec){
            cout << i << " ";
        }
        cout << '\n';
    }
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      vector<vector<int>> cost(m, vector<int>(n, 0));
      cost[0][0]=grid[0][0];

      for(int c=1;c<n;++c){
          cost[0][c] = cost[0][c-1]+grid[0][c];
      }
      for(int r=1;r<m;++r){
          cost[r][0] = cost[r-1][0]+grid[r][0];
      }
      for(int r=1;r<m;++r){
          for(int c=1;c<n;++c){
              cost[r][c] = min(cost[r-1][c], cost[r][c-1]) + grid[r][c];
          }
      }

    //   print(cost);

      return cost[m-1][n-1];
    }
};

int main(){
  Solution so;
  vector<vector<int>> grid{
    {1,3,1},
    {1,5,1},
    {4,2,1}
  };
  

  cout << so.minPathSum(grid) << endl;// 7
  
}