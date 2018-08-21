#include "template.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        /* 若前一个位置和后一个位置为0，并且当前为0，种下一颗树
           开头和结尾特殊处理一下
        */
        int cnt=0;
        int pre, back;
        for(int i=0;i<a.size() && cnt<n;++i){
          pre = i==0? 0 : a[i-1];
          back = i==a.size()-1? 0 : a[i+1];
          if(pre==0 && back==0 && a[i]==0){
            a[i]=1;
            cnt++;
          }
        }
        // print(a);
        if(cnt==n)return true;
        return false;
    }
};


int main(){
    Solution so;
    vector<int> a{1,0,0,0,1};
    cout << so.canPlaceFlowers(a, 2) << endl;
}