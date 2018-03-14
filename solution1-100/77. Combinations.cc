#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

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
    void combine(int n, int k, int start, vector<int> &vec, vector<vector<int>>& res){
      if(k==0){
        // vec.push_back(n);
        res.push_back(vec);
        // vec.pop_back();
        return;
      }
      for(int i=start;i<=n-k+1;++i){
          // printf("k:%d i: %d\n", k, i);
          vec.push_back(i);
          combine(n, k-1, i+1, vec, res);
          vec.pop_back();
        }
        // printf("\n");
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        combine(n, k, 1, vec, res);
        return res;
    }
};

int main(){
  Solution so;
  auto matrix = so.combine(4, 2);
  print(matrix);
}