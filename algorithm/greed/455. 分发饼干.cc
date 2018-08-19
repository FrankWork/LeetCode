#include "template.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /* g和s从大到小排序
           当前s能满足当前g， 计数加一
           否则，忽略当前g
        */       
       sort(g.begin(), g.end(), greater<int>()) ;
       sort(s.begin(), s.end(), greater<int>());

      //  print(g);
      //  print(s);

       int i=0, j=0, n=0;// g和s的下标
       while(j<s.size() && i<g.size()){
         if(s[j]>=g[i]){
           j++;i++;n++;
         }else{
           i++;
         }
       }
       return n;
    }
};

int main(){
  vector<int> g{1,2,3};
  vector<int> s{1,1};
  Solution so;
  cout << so.findContentChildren(g, s)<<endl;

}