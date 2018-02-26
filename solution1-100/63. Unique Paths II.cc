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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();

      for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
          obstacleGrid[i][j] = 0-obstacleGrid[i][j];
        }
      }
      // init 0-row, 0-col to 1 or -1
      for(int i=0;i<m;++i){
        if(obstacleGrid[i][0]!=-1){
          obstacleGrid[i][0]=1;
        }else{
          break;
        }
      }
      for(int i=0;i<n;++i){
        if(obstacleGrid[0][i]!=-1){
          obstacleGrid[0][i]=1;
        }else{
          break;
        }
      }

      for(int r=1;r<m;++r){
        for(int c=1;c<n;++c){
          if(obstacleGrid[r][c]!=-1){
            if(obstacleGrid[r-1][c] != -1){
              obstacleGrid[r][c] += obstacleGrid[r-1][c];  
            }
            if(obstacleGrid[r][c-1] != -1){
              obstacleGrid[r][c] += obstacleGrid[r][c-1];  
            }
          }
        }
      }

      print(obstacleGrid);
      
      if(obstacleGrid[m-1][n-1] != -1){
          return obstacleGrid[m-1][n-1];
      }
      
      return 0;
    }
};

int main(){
  Solution so;
  // vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
  // obstacleGrid[1][1] = 1;

  // vector<vector<int>> obstacleGrid(1, vector<int>(1, 1));

  vector<vector<int>> obstacleGrid(1, vector<int>(2, 0));
  obstacleGrid[0][0] = 1;

  cout << so.uniquePathsWithObstacles(obstacleGrid) << endl;
  
}