#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void combinationSum(vector<int>& candidates, int target, 
    vector<vector<int>>& result, vector<int> &combination, int start){
      if(target == 0){
        result.push_back(combination);
        return;
      }

      for(int i=start;i<candidates.size();i++){
        if(i>start && candidates[i]==candidates[i-1]){
          continue;
        }
        if(candidates[i]<=target){
          combination.push_back(candidates[i]);
          combinationSum(candidates, target-candidates[i], result, combination, i+1);
          combination.pop_back();
        }
        
      }

  }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSum(candidates, target, result, combination,0);
      
      return result;
    }
};

int main(){
  Solution so;
  vector<int> nums={10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> result = so.combinationSum2(nums, 8);
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // vector<int> nums2={1, 1, 1, 1, 2, 2, 4};
  // result = so.combinationSum2(nums2, 4);
  // for(int i=0;i<result.size();i++){
  //   for(int j=0;j<result[i].size();j++){
  //     cout << result[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}