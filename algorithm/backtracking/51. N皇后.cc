#include "../template.h"


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
          /* 每行一个皇后
              每个皇后不能在同一行，同一列，同一对角线上

            对行进行回溯
          */
         vector<vector<string>> res;
         vector<string> board(n, string(n, '.'));

         dfs(res, board, n, 0);
         return res;
    }

    void dfs(vector<vector<string>> &res, vector<string> &board, int n, int r){
      // r: row
      if(r==n){
        res.push_back(board);
        return;
      }

      for(int c=0;c<n;++c){// col
        if(isValid(board, n, r, c)){
          board[r][c]='Q';
          dfs(res, board, n, r+1);
          board[r][c]='.';          
        }
      }

    }

    bool isValid(vector<string> &board, int n, int r, int c){
      // // 行
      // for(int c=0;c<n;++c)
      //   if(board[x][c]=='Q')
      //     return false;
      
      // 列
      for(int i=0;i<n;++i)
        if(board[i][c]=='Q')
          return false;

      // 对角线
      for(int i=1; r-i>=0 && c-i>=0;i++){
          if(board[r-i][c-i]=='Q')return false;
        }

      for(int i=1;r-i>=0 && c+i<n;i++){
        if(board[r-i][c+i]=='Q')return false;
      }

      return true;
    }
};

int main(){

}