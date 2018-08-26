#include "template.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int k) {
        int l= binarySearch(a, k);
        int r= binarySearch(a, k+1)-1;
        if(l==a.size() || a[l] != k){
          l=-1;
          r=-1;
        }

        vector<int> res{l,r};
        return res;
    }
    int binarySearch(vector<int>& a, int k){
      /* 查找左端
         a[m]>=k,     [l, m-1]
         a[m]<k,     [m+1, r]

        1       1
        l,r,m

        1       2
        l,r,m
         
      */
      int l=0, r=a.size()-1;
      while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]>=k) r=m-1;
        else l=m+1;
      }
      return l;
    }
};

int main(){
  vector<int> a{1};
  Solution so;
  cout << so.binarySearch(a, 2)<<endl;
  
}