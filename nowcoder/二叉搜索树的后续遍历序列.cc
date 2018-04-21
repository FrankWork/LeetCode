#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

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

class Solution {
public:
    bool recsive(vector<int>&seq, int l, int r){
        if(l>=r)return true;
        int i=r-1;
        for(;i>=l;--i){
            if(seq[i]<seq[r])break;
        }
        for(int j=i;j>=l;--j){
            if(seq[j]>seq[r])return false;
        }
        
        return recsive(seq, i+1, r-1) && recsive(seq, l, i);
    }
    
    bool VerifySquenceOfBST(vector<int> &seq) {
        int n=seq.size();
        if(n==0)return false;
        return recsive(seq, 0, n-1);
    }
};

int main(){
  Solution so;
  vector<int> nums{4,8,6,12, 16,14,10};
  cout << so.VerifySquenceOfBST(nums)<<endl;
  
  return 0;
}