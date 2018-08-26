#include "../template.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& a) {
      /* 在每个位置深度优先搜索，位置为1，岛屿数目加1，
         深度优先搜索时，将相邻为1的点置0，防止重复计数
        
      */
       if(a.size()==0 || a[0].size()==0)return 0;
       int n=a.size(), m=a[0].size();
       int res=0;

        for(int i=0;i<n;++i){
          for(int j=0;j<m;++j){
            if(a[i][j]=='1'){
              res++;
              dfs(a, n, m, i, j);
            }
            
          }
        }
        return res;
    }
    int dfs(vector<vector<char>> &a, int row, int col, int i, int j){
      if(i<0||i>=row || j<0||j>=col){
        return 0;
      }
      if(a[i][j]=='1'){
        a[i][j]='0';
        dfs(a, row, col, i+1, j);
        dfs(a, row, col, i-1, j);
        dfs(a, row, col, i, j+1);
        dfs(a, row, col, i, j-1);
      }
      
      
    }
};

int main(){

}