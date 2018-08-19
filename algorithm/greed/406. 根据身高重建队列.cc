#include "template.h"


bool cmp(const pair<int,int>&a, const pair<int,int>&b){
  if(a.first==b.first) return a.second<b.second;
  return a.first>b.first;
}


class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& a) {
        /*
          身高较高的人先插入 (h, k)
          按身高递减和人数递增排序，按k个数插入到新队伍中
        */
       sort(a.begin(), a.end(), cmp);

      //  for(auto it=a.begin();it!=a.end();++it)
      // printf("(%d,%d) ", it->first, it->second);
      //   cout <<endl;

       vector<pair<int, int>> res;
       for(int i=0;i<a.size();++i){
         res.insert(res.begin()+a[i].second, a[i]);
        //  for(auto it=res.begin();it!=res.end();++it)
        //   printf("(%d,%d) ", it->first, it->second);
        // cout <<endl;
       }

       return res;
    }
};

int main(){
    vector<pair<int, int>> a{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution so;
    auto res=so.reconstructQueue(a);
    for(auto it=res.begin();it!=res.end();++it)
      printf("(%d,%d) ", it->first, it->second);
    cout <<endl;
      // cout << it->first << " "<< it->second<<endl;
    // vector<int> nums;
    // nums.insert(nums.begin(), -1);
}