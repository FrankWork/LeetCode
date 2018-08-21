#include "template.h"

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
      /*  记录更改的次数
      
      出现递减，a[i]<a[i-1]，需要考虑的是应该修改数组的哪个数
            令a[i-1]=a[i], 让前面的数变小
      出现递减，a[i]<a[i-2], 
            令 a[i] = a[i-1], 增大当前的数
      以上两种情况同时出现
            令 a[i] = a[i-1], 增大当前的数
      更改次数<2，返回真； 否则，返回假
      */
        int n=0;
       
        for(int i=1;i<a.size()  && n<2;++i){
          if(i>1 && a[i]<a[i-2]){
            a[i]=a[i-1];
            n++;
          }else if(i>0 && a[i]<a[i-1]){
            a[i-1] = a[i];
            n++;
          } 
          print(a);
        }
        return n<=1;
    }
};

int main(){
    Solution so;
    vector<int> a{3,4,2,3};
    // vector<int> a{4,2,3};
    cout << so.checkPossibility(a)<<endl;
}