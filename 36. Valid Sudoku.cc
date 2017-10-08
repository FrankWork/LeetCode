#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9){
          return false;
        }
        for(int i=0;i<9;i++){
          if(board[i].size()!=9){
            return false;
          }
        }

        vector<int> counter(9, 0);
        int n,i,j;

        for(i=0;i<9;i++){
          // row 
          for(j=0;j<9;j++){
            counter[j]=0;
          }
          for(j=0;j<9;j++){
            if(board[i][j]!='.'){
              n = board[i][j]-'1';
              counter[n]++;
            }
          }
          for(j=0;j<9;j++){
            if(counter[j]>1){
              return false;
            }
          }

          // column
          for(j=0;j<9;j++){
            counter[j]=0;
          }
          for(j=0;j<9;j++){
            if(board[j][i]!='.'){
              n = board[j][i]-'1';
              counter[n]++;
            }
          }
          for(j=0;j<9;j++){
            if(counter[j]>1){
              return false;
            }
          }
        }

        //box
        int k,l;
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            // 3*i,3*j;+1,+2
            for(k=0;k<9;k++){
              counter[k]=0;
            }
            for(k=3*i;k<3*i+3;k++){
              for(l=3*j;l<3*j+3;l++){
                if(board[k][l]!='.'){
                  n = board[k][l]-'1';
                  counter[n]++;
                }
              }
            }
            for(k=0;k<9;k++){
              if(counter[k]>1){
                return false;
              }
            }
          }
        }
        

        return true;
    }
};

int main(){
  Solution so;

  // vector<vector<char>> board;
  // vector<char> n1 = {'5',  '3',  '.',  '.',  '7',  '.',  '.',  '.',  '.'};
  // vector<char> n2 = {'6',  '.',  '.',  '1',  '9',  '5',  '.',  '.',  '.'};
  // vector<char> n3 = {'.',  '9',  '8',  '.',  '.',  '.',  '.',  '6',  '.'};
  // vector<char> n4 = {'8',  '.',  '.',  '.',  '6',  '.',  '.',  '.',  '3'};
  // vector<char> n5 = {'4',  '.',  '.',  '8',  '.',  '3',  '.',  '.',  '1'};
  // vector<char> n6 = {'7',  '.',  '.',  '.',  '2',  '.',  '.',  '.',  '6'};
  // vector<char> n7 = {'.',  '6',  '.',  '.',  '.',  '.',  '2',  '8',  '.'};
  // vector<char> n8 = {'.',  '.',  '.',  '4',  '1',  '9',  '.',  '.',  '5'};
  // vector<char> n9 = {'.',  '.',  '.',  '.',  '8',  '.',  '.',  '7',  '9'};
  // board.push_back(n1);
  // board.push_back(n2);
  // board.push_back(n3);
  // board.push_back(n4);
  // board.push_back(n5);
  // board.push_back(n6);
  // board.push_back(n7);
  // board.push_back(n8);
  // board.push_back(n9);
  // bool result = so.isValidSudoku(board);
  // cout << result << endl;
  // [".........",".........",".9......1","8........",".99357...",
  //   ".......4.","...8.....",".1....4.9","...5.4..."]
  vector<vector<char>> board;
  vector<char> n1 = {'.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.'};
  vector<char> n2 = {'.',  '9',  '.',  '.',  '.',  '.',  '.',  '.',  '.'};
  vector<char> n3 = {'.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '1'};
  vector<char> n4 = {'8',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.'};
  vector<char> n5 = {'.',  '9',  '.',  '3',  '5',  '7',  '.',  '.',  '.'};
  vector<char> n6 = {'.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '4'};
  vector<char> n7 = {'1',  '.',  '.',  '8',  '.',  '.',  '.',  '.',  '.'};
  vector<char> n8 = {'.',  '1',  '.',  '.',  '.',  '.',  '4',  '.',  '9'};
  vector<char> n9 = {'.',  '.',  '.',  '5',  '.',  '4',  '.',  '.',  '.'};
  board.push_back(n1);
  board.push_back(n2);
  board.push_back(n3);
  board.push_back(n4);
  board.push_back(n5);
  board.push_back(n6);
  board.push_back(n7);
  board.push_back(n8);
  board.push_back(n9);
  bool result = so.isValidSudoku(board);
  cout << result << endl;
}
