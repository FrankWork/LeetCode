#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> &path){
    for(auto vec: path){
        for(int i: vec){
            cout << i << " ";
        }
        cout << '\n';
    }
}

int move(pair<int, int> p0, vector<pair<int, int>>& steps, vector<vector<char>>& board){
    int n=board.size(), m=board[0].size();
    vector<vector<int>> dp_sum(n, vector<int>(m, -1));
    dp_sum[p0.first][p0.second]=0;

    queue<pair<int, int>> adjNodes;
    int tx, ty;
    for(int i=0;i<steps.size();++i){
      tx=p0.first+steps[i].first;
      ty=p0.second+steps[i].second;
      if(tx>=0&&tx<n && ty>=0&&ty<m && dp_sum[tx][ty]==-1 && board[tx][ty]!='X'){
        // dp_sum[tx][ty]=dp_sum[0][0]+1;
        pair<int, int> node(tx, ty);
        adjNodes.push(node);
      }
    }

    while(!adjNodes.empty()){
      pair<int, int> curNode = adjNodes.front();
      adjNodes.pop();
      
      int minStep=m*n;
      for(int i=0;i<steps.size();++i){
        tx=curNode.first-steps[i].first;
        ty=curNode.second-steps[i].second;

        if(tx>=0&&tx<n && ty>=0&&ty<m && dp_sum[tx][ty]!=-1){
          minStep = min(minStep, dp_sum[tx][ty]);
        }
      }
      dp_sum[curNode.first][curNode.second] = minStep +1;

      for(int i=0;i<steps.size();++i){
        tx=curNode.first+steps[i].first;
        ty=curNode.second+steps[i].second;
        if(tx>=0&&tx<n && ty>=0&&ty<m && dp_sum[tx][ty]==-1 && board[tx][ty]!='X'){
          pair<int, int> node(tx, ty);
          adjNodes.push(node);
        }
      }

    }

    print(dp_sum);

    int maxStep=-1;
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        maxStep = max(maxStep, dp_sum[i][j]);
        if(board[i][j]=='.' && dp_sum[i][j]==-1){
          return -1;
        }
      }
    }
    return maxStep;
}

int main(){
  int n, m;
  cin >>n>>m;
  vector<vector<char>> board(n, vector<char>(m));
    
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cin>>board[i][j];
    }
  }
  pair<int, int> p0;
  cin >> p0.first >> p0.second;
  int k;
  cin >>k;
  vector<pair<int, int>> steps(k);
  for(int i=0;i<k;++i){
    cin>>steps[i].first>>steps[i].second;
  }

  int x = move(p0, steps, board);
  cout << x << endl;
  
}