#include "template.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*桶排序， 第i个桶中存储频率为i的数字， 从后向前遍历桶
        */
       unordered_map<int,int> freq;
       for(int i=0;i<nums.size();++i){
         int t=nums[i];
         freq[t]++;
       }

       vector<vector<int>> buck(nums.size(), vector<int>());
       for(auto it=freq.begin(); it!=freq.end();++it){
         buck[it->second-1].push_back(it->first);
       }
      
       vector<int> res;    
       for(int i=buck.size()-1;i>=0;--i){
         if(buck[i].size()>0){
           int j=0;
           while(j<buck[i].size() && res.size()<k){
             res.push_back(buck[i][j++]);
           }
         }
         if(res.size()==k)break;
       }
       return res;

    }
};

int main(){
  Solution so;
  vector<int> nums{1};
  vector<int> res=so.topKFrequent(nums, 1);
  print(res);
}