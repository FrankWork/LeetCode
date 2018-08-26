#include "../template.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        /*  有n个人，遍历一次后，就不要再重复遍历了
        */
       if(a.size()==0 || a[0].size()==0){
         return 0;
       }
       
       int res=0;
       int n=a.size();
       vector<bool> used(n);
       for(int i=0;i<n;i++){
         if(!used[i]){
           dfs(a, i, used);
           res++;
         }
       }
       
       return res;
    }
    void dfs(vector<vector<int>>& a, int i, vector<bool>& used){

      used[i] = true;
      for(int j=0;j<a.size();++j){
        if(a[i][j]==1 && !used[j]){
          dfs(a, j, used);
        }
      }
      return;
    }
};


int main(){
    vector<vector<int>> a{
      {1,0,0,1},
      {0,1,1,0},
      {0,1,1,1},
      {1,0,1,1}
    };

    Solution so;
    cout << so.findCircleNum(a) << endl; //1

}