#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int l=1,r=2;
        vector<int> cache;
        vector<vector<int>> res;
        while(l!=(sum+1)/2){// l-1 + l = sum
          int t=(l+r)*(r-l+1)/2; // sum = (a1+an)*n/2
          if(t==sum){
            cache.clear();
            for(int i=l;i<=r;++i){
              cache.push_back(i);
            }
            res.push_back(cache);
            ++l;
          }else if(t<sum){
            ++r;
          }else{
            ++l;
          }
        }
        return res;
    }
};

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}


template<class T>
void print2d(vector<vector<T>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}

int main(){
  Solution so;
  auto res =  so.FindContinuousSequence(100);
  print2d(res);
}