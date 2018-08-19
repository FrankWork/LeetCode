#include "template.h"

bool cmp(pair<int,int>&a, pair<int,int>&b){
  return a.second<b.second;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& a) {
        /*
          计算不重叠的区间个数 [1,2],[2,3]算重叠区间
        */
       int n=a.size();
       if(n==0) return 0;
       else if(n==1) return 1;

       sort(a.begin(), a.end(), cmp);
       int last=a[0].second;
       int res=1;
       for(int i=1;i<n;++i){
         if(a[i].first>last){
           res++;
           last=a[i].second;
         }
       }
       return res;
    }
};

int main(){
    Solution so;
    vector<pair<int,int>> a{{10,16}, {2,8}, {1,6}, {7,12}};
    cout << so.findMinArrowShots(a)<<endl;
}