#include "../template.h"

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& a) {
        /* 从太平洋和大西洋分别逆向查找，并分别记录查找路径上的点
           某个点出现在太平洋和大西洋两种路径上时，就是答案之一
        */
        vector<pair<int,int>> res;
        if(a.size()==0 || a[0].size()==0)return res;
        int row=a.size(), col=a[0].size();
        vector<vector<bool>> pac(row, vector<bool>(col));// 太平洋路径
        vector<vector<bool>> atl(row, vector<bool>(col));// 大西洋路径
        
        // 查找路径
        for(int i=0;i<row;++i){
          dfs(a, pac, i, 0);
          dfs(a, atl, i, col-1);
        }
        for(int j=0;j<col;++j){
          dfs(a, pac, 0, j);
          dfs(a, atl, row-1, j);
        }
        // 找出答案
        for(int i=0;i<row;++i){
          for(int j=0;j<col;++j){
            if(pac[i][j]&&atl[i][j])
              res.push_back({i,j});
          }
        }
        return res;
    }
    void dfs(vector<vector<int>>&a, vector<vector<bool>>& path, int i, int j){
        int row=a.size(), col=a[0].size();
        if(i<0||i>=row || j<0||j>=col)return;

        path[i][j]=true;

        vector<pair<int,int>> direction{ {1,0}, {-1, 0}, {0,1}, {0,-1} };
        int next_i, next_j;
        for(pair<int,int>& d: direction){
          next_i = i+d.first;
          next_j = j+d.second;
          if(next_i<0||next_i>=row || next_j<0||next_j>=col)continue;
          if(a[i][j] <= a[next_i][next_j] && !path[next_i][next_j]){
            dfs(a, path, next_i, next_j);
          }
        }
    }
};


int main(){
  Solution  so;
  vector<vector<int>> a{
    {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}
  };
  so.pacificAtlantic(a);
}