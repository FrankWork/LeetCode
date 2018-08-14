#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;


class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> &array) {
      int current=-1, all=-1;
      for(int i=0;i<array.size();++i){
        current = max(array[i], current+array[i]);
        all = max(current, all);
      }
      return all;
    }
};

int main(){
  vector<int> nums{6,-3,-2,7,-15,1,2,2};
  Solution so;
  cout << so.FindGreatestSumOfSubArray(nums)<<endl;
}