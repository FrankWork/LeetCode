#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, 
                          vector<vector<int>>& result,
                          vector<int> &combination,
                          int start){
      if(target<0){
        return;
      }else if(target == 0){
        result.push_back(combination);
        return;
      }

      for(int i=start;i<candidates.size();i++){
        combination.push_back(candidates[i]);
        combinationSum(candidates, target-candidates[i], result, combination, i);
        combination.pop_back();
      }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSum(candidates, target, result, combination, 0);
      
      return result;
    }

};

int main(){
  Solution so;
  vector<int> nums={2, 3, 6, 7};
  vector<vector<int>> result = so.combinationSum(nums, 7);
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  vector<int> nums2={1,2};
  result = so.combinationSum(nums2, 4);
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  vector<int> nums3={4, 2, 8};
  result = so.combinationSum(nums3, 8);
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}