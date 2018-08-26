#include "../template.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& a) {
        /* 从每一个点都搜索一遍，找出最大面积
            不要重复搜索地点，在原位置标记
        */
       if(a.size()==0 || a[0].size()==0)return 0;
       int n=a.size(), m=a[0].size();
       int res=0;
       for(int i=0;i<n;++i){
         for(int j=0;j<m;++j){
           int t = dfs(a, n, m, i, j);
           res = max(res, t);
         }
       }
       return res;
    }

    int dfs(vector<vector<int>> &a, int row, int col, int i, int j){
      printf("%d %d\n", i, j);
      if(i<0||i>=row || j<0||j>=col) return 0;
      if(a[i][j]==0) return 0;

      a[i][j] = 0;
      int res=1;
      res += dfs(a, row, col, i+1, j);
      res += dfs(a, row, col, i, j+1);
      res += dfs(a, row, col, i-1, j);
      res += dfs(a, row, col, i, j-1);

      // a[i][j] = 1;
      
      return res;
    }
};

int main(){
    Solution so;
    vector<vector<int>> a{
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

    cout << so.maxAreaOfIsland(a)<<endl;
}