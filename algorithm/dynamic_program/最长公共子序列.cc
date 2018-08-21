#include "template.h"

class LCS {
public:
    int findLCS(const string &A, int n, const string & B, int m) {
        /*
            f(i, j) A(0..i)和B(0..j)的LCS
            f(i, j) = f(i-1, j-1)+1,               A[i]==B[j]
                      max( f(i-1,j), f(i,j-1) ),   A[i]!=B[j]
        */
       vector<vector<int>> dp(n+1, vector<int>(m+1));
       for(int i=1;i<=n;++i){
           for(int j=1;j<=m;++j){
               if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
               else dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
           }
       }
       return dp[n][m];
    }
};

int main(){

    LCS lcs;
    cout << lcs.findLCS("1A2C3D4B56",10,"B1D23CA45B6A",12)<<endl;//6
}   