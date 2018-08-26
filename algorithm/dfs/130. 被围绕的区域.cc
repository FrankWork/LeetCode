#include "../template.h"

class Solution {
public:
    void solve(vector<vector<char>>& a) {
        /* 把最外侧的'O'标记出来，剩下的填充
        */
       if(a.size()==0 || a[0].size()==0)return;
       int row=a.size(), col=a[0].size();
       // 找最外侧
       for(int i=0;i<row;++i){
         dfs(a, i, 0);
         dfs(a, i, col-1);
       }
       for(int j=0;j<col;++j){
         dfs(a, 0, j);
         dfs(a, row-1, j);
       }
      // 转换标记
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          if(a[i][j]=='T') a[i][j]='O';
          else if(a[i][j]=='O') a[i][j]='X';
        }
      }
    }

    void dfs(vector<vector<char>>& a, int i, int j){
      int row=a.size(), col=a[0].size();
      if(i<0||i>=row || j<0||j>=col) return;

      if(a[i][j]=='O'){
        a[i][j]='T';
        dfs(a, i+1, j);
        dfs(a, i, j+1);
        dfs(a, i-1, j);
        dfs(a, i, j-1);
      }
    }
};


int main(){

}