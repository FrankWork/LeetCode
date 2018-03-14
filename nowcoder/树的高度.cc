#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
 
int dfs(vector<vector<int>>& tree, int p){
  // printf("p:%d\n", p);
  if(p==0 && tree[p].size()==0) return 0;
  if(tree[p].size()==0){
    return 1;
  }
  int depth = dfs(tree, tree[p][0]);
  if(tree[p].size()==2){
    depth = max(depth, dfs(tree, tree[p][1]));
  }
  return depth+1;
}
 
int main(){
    int n;
    cin >>n;
    vector<vector<int>> tree(n, vector<int>());
    int p, c, left, right, depth=0, maxDepth=0;
    for(int i=0;i<n-1;++i){
        cin >> p >> c;
        if(tree[p].size()<2){
          tree[p].push_back(c);
        }
    }
    cout << dfs(tree, 0);
    return 0;
}