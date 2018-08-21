#include "template.h"

class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char k) {
        /* 找上界
           找不到，输出第一个

           ["c","f","j"] "d"
        */
       int n = a.size();
       int l=0, r=n-1;
       int m;
       while(l<=r){
        //  printf("%d %d %c %c\n", l, r, a[l], a[r]);
         m = l+(r-l)/2;
         if(a[m]<=k) l=m+1;
         else r=m-1;
       }
      
       return l<n? a[l] : a[0];
    }
};


int main(){
  vector<char> a{'c', 'f', 'j'};
  Solution so;
  cout << so.nextGreatestLetter(a, 'j') << endl;
}