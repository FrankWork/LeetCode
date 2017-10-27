#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      return res;
    }
};

void print(vector<vector<int>> res){
  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
      cout << res[i][j]<<" ";
    }
    cout << "\n";
  }
  cout << endl;
}

int main(){
  Solution so;
  vector<int> nums{1,2,3};
  print(so.permute(nums));
}