#include "../template.h"

int minPath(vector<vector<int>>& a, int x, int y){
  /*
    BFS 只能求解无权图的最短路径
    队列：用来存储每一轮遍历得到的节点
    标记：对于遍历过的节点，应该将它标记，防止重复遍历 （在原位置标记）
  */
    int len=0;
    if(a.empty() || a[0].empty() ) return len;

    vector<pair<int, int>> direction{{1,0}, {-1,0}, {0,1}, {0, -1}};
    int m=a.size(), n=a[0].size();
    queue<pair<int,int>> q;
    q.push({0, 0});
    while(!q.empty()){
      int k=q.size();
        len++;

      while(k-- > 0){
        pair<int,int> cur = q.front();
        q.pop();
        for(auto d: direction){
          pair<int,int> next{cur.first+d.first, cur.second+d.second}; 
          if(next.first<0||next.first>=m || next.second<0||next.second>=n)
              continue;
          if(next.first==0 && next.second==0)
              continue;

          a[next.first][next.second] = 0;//标记
          if(next.first==x && next.second==y)
              return len;
          q.push(next);
        }
      }
    }
    return -1;
}
int main(){
    vector<vector<int>> a{
      {1,1,0,1},
      {1,0,1,0},
      {1,1,1,1},
      {1,0,1,1}
    };

    cout << minPath(a, 3, 3)<<endl;
}