#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &path){
    for(auto vec: path){
        for(int i: vec){
            cout << i << " ";
        }
        cout << '\n';
    }
}

class Solution {
public:
    void search(int m, int n, int x, int y, int & sum){
        if(x==n-1 && y==m-1){
            // cout << sum << endl;
            ++sum;
            return;
        }

        if(x+1<n){
            search(m, n, x+1, y, sum);
        }
        if(y+1<m){
            search(m, n, x, y+1, sum);
        }
    }
    int uniquePaths(int m, int n) {
        // int sum=0;
        // search(m, n, 0, 0, sum);
        // return sum;
        vector<vector<int>> path(m, vector<int>(n, 1));
        

        for(int r=1;r<m;++r){
            for(int c=1;c<n;++c){
                path[r][c] = path[r-1][c] + path[r][c-1];
            }
        }

        // print(path);

        return path[m-1][n-1];
    }
};

int main(){
  Solution so;
  cout << so.uniquePaths(3, 3) << endl;
  cout << so.uniquePaths(3, 7) << endl;
  cout << so.uniquePaths(23, 12) << endl;
}