#include <iostream>
#include <vector>

using namespace std;

int move(int x, int y, vector<vector<int>>& steps, vector<vector<int>>& board, vector<vector<int>>& used){
    int n=steps.size(), m=steps[0].size();
    if(x==n-1 && y==m-1){
        return 1;
    }
    int sum=-1;
    int tx, ty, res;
    for(int i=0;i<steps.size();++i){
        tx = x+steps[i][0];
        ty = y+steps[i][1];
        if(tx>=0 && tx<n && ty>=0 && ty<m && used[tx][ty]==0 && board[tx][ty]=='.'){
            used[tx][ty]=1;
            res = move(tx, ty, steps, board, used);
            if(res!=-1)
            used[tx][ty]=0;
        }
    }
    return sum;
}

int main(){
  int n, m;
  cin >>n>>m;
  vector<vector<char>> board(n, vector<char>(m));
  vector<vector<char>> used(n, vector<char>(m));
    
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cin>>board[i][j];
    }
  }
  int x0, y0;
  cin >> x0, y0;
  int k;
  cin >>k;
  vector<vector<int>> steps(k, vector<int>(2));
  for(int i=0;i<k;++i){
    cin>>steps[i][0]>>steps[i][1];
  }
  
}