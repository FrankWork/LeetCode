#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m;
  cin >>n>>m;
  vector<vector<char>> board(n, vector<char>(m));
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