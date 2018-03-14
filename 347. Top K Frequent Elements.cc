#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums){
          ++count[num];
        }
        int n = nums.size();
        vector<vector<int>> bucket(n+1, vector<int>());
        for(auto& kv: count){
          bucket[kv.second].push_back(kv.first);
        }
        vector<int> res;
        for(int i=bucket.size()-1;i>=0 && res.size()<k;--i){
          for(auto num: bucket[i]){
            res.push_back(num);
          }
        }
        return res;
    }
};

int main(){
  Solution so;

  // vector<int> nums{1,1,1,2,2,3};
  // vector<int> res = so.topKFrequent(nums, 2);//[1,2]

  vector<int> nums{1};
  vector<int> res = so.topKFrequent(nums, 1);//[1,2]

  for(int x:res){
    cout << x << " ";
  }
  cout << endl;

  return 0;
}