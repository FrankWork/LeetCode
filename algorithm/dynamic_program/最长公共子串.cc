#include "template.h"

class LongestSubstring {
public:
    int findLongest(const string & A, int n, const string & B, int m) {
        /*
        f(i, j)  以i结尾的A子串和以j结尾的B子串的连续长度
        f(i, j) = f(i-1, j-1)+1,               A[i]==B[j]
                   
        */
       int best=-1;
       vector<vector<int>> dp(n+1, vector<int>(m+1));
       for(int i=1;i<=n;++i){
           for(int j=1;j<=m;++j){
               if(A[i-1]==B[j-1]){
                   dp[i][j] = dp[i-1][j-1]+1;
                   best = max(best, dp[i][j]);
               }
           }
       }
        // print2d(dp);
       return best;
    }
};

int main(){
    LongestSubstring l;
    cout << l.findLongest("1AB2345CD",9,"12345EF",7) << endl;
}