#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string str;
    vector<vector<int>> land(n, vector<int>(m));
    for(int i=0;i<n;++i){
        cin>>str;
        for(int j=0;j<m;++j){
            land[i][j] = str[j]-'0';
        }
    }
    int val=10;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            val=min(val, land[i][j]);
        }
    }
    cout << val;
    return 0;
}

// 4 2
// 75 1468