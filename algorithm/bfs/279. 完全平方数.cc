#include "../template.h"


class Solution {
public:
    int numSquares(int n) {
        /*
        可以将每个整数看成图中的一个节点，如果两个整数之差为一个平方数，
          那么这两个整数所在的节点就有一条边。

          题目就是求解从节点 n 到节点 0 的最短路径。
            (12) -9- (3) -1- (2) -1- (1) -1- (0)
                 -4- (8) -4- (4) -4- (0)
                 -1- (11)-9- (3)...
        */
       vector<int> sqs = getSquares(n);
       vector<bool> used(n+1);
      //  print(sqs);
      queue<int> q;
      q.push(n);
      int level = 0;

      while(!q.empty()){
        int nq = q.size();
        level++;

        while(nq-- > 0){
            int cur = q.front();
            q.pop();

            for(int x: sqs){
              int next=cur-x;
              
              if(next==0){return level;}
              else if(next<0) break;

              if(used[next]) continue;

              q.push(next);
              used[next] = true;
            }
        }
      }
      return n;
    }

    vector<int> getSquares(int n){
      // 生成完全平方数
      // 1, 4, 9, 16,
      vector<int> res;
      for(int i=1; ;i++){
        int t=i*i;
        if(t>n) break;
        res.push_back(t);
      }
      return res;
    }
};

int main(){
    Solution so;
    so.numSquares(16);
}