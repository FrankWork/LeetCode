#include <vector>
#include <string>
#include <iostream>
using namespace std;

const char EMPTY = '.';
const char QUEEN = 'Q';

class Solution {
public:
    void solve(int r, int n, vector<string> &tmp, vector<vector<string>> &results){
      if(r>=n){
        results.push_back(tmp);
        return;
      }

      for(int c=0;c<n;++c){
        bool is_valid=true;

        for(int i=0;i<r;++i){
          if(tmp[i][c]==QUEEN){is_valid=false;}
        }
        for(int i=1; r-i>=0 && c-i>=0;i++){
          if(tmp[r-i][c-i]==QUEEN){is_valid=false;}
        }

        for(int i=1;r-i>=0 && c+i<n;i++){
          if(tmp[r-i][c+i]==QUEEN){is_valid=false;}
        }
        
        if(is_valid==true){
          tmp[r][c]=QUEEN;
          solve(r+1, n, tmp, results);
          tmp[r][c]=EMPTY;
        }
      }
    }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> results;
      vector<string> tmp(n);
      
      for(int i=0;i<n;++i){
        tmp[i] = string(n, EMPTY);
      }

      solve(0, n, tmp, results);
        
      return results;
    }

};


int main(){
  Solution so;

  int n=4;

  for(int n=4;n<=5;n++){
    auto res = so.solveNQueens(n);
    
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
          cout << res[i][j]<<endl;
        }
        cout << '\n';
    }
      cout << '\n';
    
  }
  return 0;
}
