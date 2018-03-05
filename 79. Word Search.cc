#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

template<class T>
void print(vector<vector<T>> &path){
    for(auto vec: path){
        for(T i: vec){
            cout << i << " ";
        }
        cout << '\n';
    }
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, vector<vector<int>>& used, 
               string word, int r, int c, int m, int n, int i) {
      // printf("r:%d c:%d %c\n", r,c, board[r][c]);
      if(i==word.length()-1){
        return true;
      }
      used[r][c]=1;
      
      
      if(r>=1 && board[r-1][c]==word[i+1] && used[r-1][c]==0){
        if(exist(board, used, word, r-1, c, m, n, i+1)) return true;
      }
      if(c>=1 && board[r][c-1]==word[i+1] && used[r][c-1]==0){
        if(exist(board, used, word, r, c-1, m, n, i+1)) return true;
      }
      if(r<m-1 && board[r+1][c]==word[i+1] && used[r+1][c]==0){
        if(exist(board, used, word, r+1, c, m, n, i+1)) return true;
      }
      if(c<n-1 && board[r][c+1]==word[i+1] && used[r][c+1]==0){
        if(exist(board, used, word, r, c+1, m, n, i+1)) return true;
      }
      

      used[r][c]=0;
      return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m==0)return false;
        int n=board[0].size();
        if(n==0)return false;
        if(word.length()==0)return true;

        for(int i=0;i<m;++i){
          for(int j=0;j<n;++j){
            if(board[i][j]==word[0]){
              // printf("i:%d j:%d\n", i,j);
              vector<vector<int>> used(m, vector<int>(n, 0));
              if(exist(board, used, word, i, j,m,n, 0)==true) 
                return true;
            }
          }
        }

        return false;
    }
};

int main()
{
  Solution so;
  vector<vector<char>> board{
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };

  cout << so.exist(board, "ABCCED") <<endl;//1
  cout << so.exist(board, "SEE") <<endl;//1
  cout << so.exist(board, "ABCB") <<endl;//0
}