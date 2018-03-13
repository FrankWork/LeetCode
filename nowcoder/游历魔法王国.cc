#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dfs(vector<vector<int>> &path, int city, int L, vector<int>& used){
    used[city] = 1;
    int depth = 0;
    for(int i=0;i<path[city].size();++i){
        int c = path[city][i];
        if(used[c]==0){
            used[c]=1;
            int d = dfs(path, c, L, used);
            if(depth < d+1){
                depth = d+1;
            }
            if(depth>L) return L;
            used[c]=0;
        }
    }
    return depth;
}
int main(){
    int n, L;
    cin >> n >> L;
    vector<int> p(n);
    for(int i=0;i<n-1;++i){
        cin>>p[i];
    }
    vector<int> used(n, 0);
    vector<vector<int>> path(n, vector<int>());
    for(int i=0;i<p.size();++i){
        path[p[i]].push_back(i+1);
    }
    
    int d = dfs(path, 0, L, used);
    cout << max(d, L)+1;
    return 0;
    
}