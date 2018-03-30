#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

void print2d(vector<vector<int>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}

int maxLeftP=-1;
vector<pair<int,int>> minPath;

void bt(vector<vector<int>>& board, vector<vector<int>>& used, int n, int m, int x, int y, int p,vector<pair<int,int>>& path){
  if(p<maxLeftP){
    return;
  }
  pair<int,int> step(x,y);
  path.push_back(step);

  if(x==0&&y==m-1){
    if(p>maxLeftP){
      maxLeftP=p;
      minPath=path;
    }
    // printf("%d\n",p);
    return;
  }
  
  used[x][y]=1;

if(y+1<m&&p-1>0 && board[x][y+1] && !used[x][y+1]){
    bt(board,used, n,m,x,y+1,p-1,path);
  }
  if(x+1<n && board[x+1][y] && !used[x+1][y]){
    bt(board, used, n, m, x+1, y, p,path);
  }
  if(x-1>=0&&p-3>=0 && board[x-1][y] && !used[x-1][y]){
    bt(board,used, n,m,x-1,y,p-3,path);
  }
  
  used[x][y]=0;
  path.pop_back();
}


int main(){
  int n,m,p;
  cin >>n>>m>>p;
  vector<vector<int>> board(n, vector<int>(m));
  
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j)
      cin>>board[i][j];
  }
 
  // print2d(board);
  vector<vector<int>> used(n, vector<int>(m));
  vector<pair<int,int>> path;
  bt(board, used, n,m,0,0, p,path);
  if(maxLeftP>=0){
    for(int i=0;i<minPath.size();++i){
      if(i!=0){
        cout <<",";
      }
      printf("[%d,%d]", minPath[i].first, minPath[i].second);
    }
    cout<<endl;
  }else{
    cout <<"Can not escape!" <<endl;
  }
  return 0;
}