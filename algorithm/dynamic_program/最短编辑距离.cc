#include "template.h"

int ed(string&a, string &b){
    /*
    f(i, j): a[0...i), b[0...j)的最短编辑距离
    f(i, j) = i,             j=0
              j,             i=0
              f(i-1, j-1),   a[i]==b[j]
              max(f(i-1,j), f(i,j-1), f(i-1, j-1))+1,   a[i]!=b[j]
    */
    int m=a.length(), n=b.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=0;i<=m;++i)
        dp[i][0]=i;
    for(int j=0;j<=n;++j)
        dp[0][j]=j;

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            } 
            else{
                dp[i][j]=min(dp[i-1][j], dp[i][j-1]);
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
                dp[i][j]++;
            }
        }
    }
    return dp[m][n];
}
int main(){
    string a, b;
    while(cin>>a>>b){
        cout << ed(a, b)<<endl;
    }
}

//    a b c
// a  0 1 2
// b  1 0 1

//     c b c d
//   0 1 2 3 4 
// a 1 1 2 3 4
// b 2 2 1 2 3
// c 3 2 2 1 2


// ZURGZMNNTIDLTCMYNXTDYYLNEWHSMJIQOPSMFTZSPLVXAMHBDWOHTXDCADUBHKKEESIOOJZRMXCEJDRZUDZHPDLMYTUGE 
// CNWDMLYGNMLRXGTDQSMSXBNSGRYRKFCJIQQXGDJMQBLTHDFLDHHQLQMPRRZXOACICPLYNQWAIM