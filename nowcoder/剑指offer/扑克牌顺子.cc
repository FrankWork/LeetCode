#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> &nums ) {
      if(nums.size()!=5){return false;}
        vector<int> tags(15, 0);
        int _min=15, _max=-1;

        for(int i=0;i<5;++i){
          int t=nums[i];
          if(t<0 || t>13)return false;
          if(t==0)continue;
          tags[t]++;
          if(tags[t]>1)return false;

          _min=min(_min, t);
          _max=max(_max, t);
        }
        if(_max-_min>5)return false;
        return true;
    }
};




int main(){
  Solution so;
  vector<int> nums{};
  cout << so.IsContinuous(nums) << endl;
}

