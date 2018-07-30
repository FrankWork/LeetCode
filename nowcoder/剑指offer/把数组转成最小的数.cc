#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <sstream>

using namespace std;

string itoa(int n){
  stringstream ss;
  string res;
  ss <<n;
  ss>>res;
  return res;
}

bool cmp(int a, int b){
  string sa, sb;
  sa = itoa(a);
  sb = itoa(b);

  return sa+sb<sb+sa;
}
class Solution {
public:
    string PrintMinNumber(vector<int> &nums) {
        string res;
        sort(nums.begin(), nums.end(), cmp);
        for(auto n:nums)
          // cout << itoa(n)<<endl;
          res+=itoa(n);
        return res;
    }
    
};

int main(){
  Solution so;
  vector<int> nums{3, 32, 321};
  cout << so.PrintMinNumber(nums)<<endl;
}