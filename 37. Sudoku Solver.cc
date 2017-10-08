#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board, int row, int column) {
        vector<int> counter(9, 0);
        int n,i,j,k,l;

        // row 
        for(i=0;i<9;i++){
          counter[i]=0;
        }
        for(i=0;i<9;i++){
          if(board[row][i]!='.'){
            n = board[row][i]-'1';
            counter[n]++;
          }
        }
        for(i=0;i<9;i++){
          if(counter[i]>1){
            return false;
          }
        }

        // column
        for(i=0;i<9;i++){
          counter[i]=0;
        }
        for(i=0;i<9;i++){
          if(board[i][column]!='.'){
            n = board[i][column]-'1';
            counter[n]++;
          }
        }
        for(i=0;i<9;i++){
          if(counter[i]>1){
            return false;
          }
        }


        //box 
        for(i=0;i<9;i++){
          counter[i]=0;
        }
        i=row/3;
        j=column/3;
        for(k=3*i;k<3*i+3;k++){
          for(l=3*j;l<3*j+3;l++){
            if(board[k][l]!='.'){
              n = board[k][l]-'1';
              counter[n]++;
            }
          }
        }
        for(i=0;i<9;i++){
          if(counter[i]>1){
            return false;
          }
        }

        return true;
    }
    bool fillBoard(vector<vector<char>>& board, 
                   vector<vector<vector<char>>> &candidate,
                   int row, int col){
       int i;
       bool valid=false;
      
       if(board[row][col]!='.'){
        if(row==8 && col==8){
          // success
          return true;
        }else if(col < 8){
            valid=fillBoard(board, candidate, row, col+1);
          }else if(row < 8){
            valid=fillBoard(board, candidate, row+1, 0);
          }
          return valid;
       }

       // pick one candidate 
       for(i=0 ;i<candidate[row][col].size();i++){
          board[row][col] = candidate[row][col][i];
          if(isValidSudoku(board,row,col)){
              if(row==8 && col==8){
                // success
                return true;
              }else if(col < 8){
                valid=fillBoard(board, candidate, row, col+1);
              }else if(row < 8){
                valid=fillBoard(board, candidate, row+1, 0);
              }
              if(valid){return valid;}
        }
      }

      board[row][col]='.';
      return valid;
    }

    void solveSudoku(vector<vector<char>>& board) {
      vector<vector<vector<char>>> candidate;
      int i,j,k,l,g,h,m,n;
      vector<int> counter(9, 0);

      // init candidate
      for(i=0;i<9;i++){
        vector<vector<char>> rows;
        candidate.push_back(rows);
        for(j=0;j<9;j++){
          vector<char> chars;
          candidate[i].push_back(chars);
          if(board[i][j]!='.'){
            continue;
          }
          //init counter
          for(k=0;k<9;k++){
            counter[k]=0;
          }
          //row in board
          for(k=0;k<9;k++){
            if(board[i][k]!='.'){
              n = board[i][k]-'1';
              counter[n]++;
            }
          }

          //column in board
          for(k=0;k<9;k++){
            if(board[k][j]!='.'){
              n = board[k][j]-'1';
              counter[n]++;
            }
          }

          //box in board
          g=i/3;
          h=j/3;
          for(k=3*g;k<3*g+3;k++){
            for(l=3*h;l<3*h+3;l++){
              if(board[k][l]!='.'){
                n = board[k][l]-'1';
                counter[n]++;
              }
            }
          }
          // cout << endl;

          // counter index to candidate
          for(k=0;k<9;k++){
            if(counter[k]==0){
              candidate[i][j].push_back(k+'1');
            }
          }
        }
      }

      bool valid = fillBoard(board, candidate, 0, 0);
      cout << valid << endl;

      for(i=0;i<9;i++){
        for(j=0;j<9;j++){
          cout << board[i][j];
        }
        cout << endl;
      }

    }
};

int main(){
  Solution so;

  vector<vector<char>> board;
  vector<char> n1 = {'5',  '3',  '.',    '.',  '7',  '.',    '.',  '.',  '.'};
  vector<char> n2 = {'6',  '.',  '.',    '1',  '9',  '5',    '.',  '.',  '.'};
  vector<char> n3 = {'.',  '9',  '8',    '.',  '.',  '.',    '.',  '6',  '.'};

  vector<char> n4 = {'8',  '.',  '.',    '.',  '6',  '.',    '.',  '.',  '3'};
  vector<char> n5 = {'4',  '.',  '.',    '8',  '.',  '3',    '.',  '.',  '1'};
  vector<char> n6 = {'7',  '.',  '.',    '.',  '2',  '.',    '.',  '.',  '6'};

  vector<char> n7 = {'.',  '6',  '.',    '.',  '.',  '.',    '2',  '8',  '.'};
  vector<char> n8 = {'.',  '.',  '.',    '4',  '1',  '9',    '.',  '.',  '5'};
  vector<char> n9 = {'.',  '.',  '.',    '.',  '8',  '.',    '.',  '7',  '9'};

  board.push_back(n1);
  board.push_back(n2);
  board.push_back(n3);
  board.push_back(n4);
  board.push_back(n5);
  board.push_back(n6);
  board.push_back(n7);
  board.push_back(n8);
  board.push_back(n9);
  so.solveSudoku(board);
  
}
