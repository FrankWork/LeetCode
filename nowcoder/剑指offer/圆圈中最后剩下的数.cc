#include "template.h"


class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
      if(n<=0||m<=0)return -1;
        vector<int> nums(n, 0);
        int left=n;
        int i=0, t=1;
        while(left!=1){
          // cout << left<<endl;
          
          if(nums[i]>0){
            i = (i+1)%n;
          }else if(nums[i]==0 && (t)%(m)==0){
            nums[i]++;
            left--;
            t++;
          //   printf("%d %d %d\n", left, i, t);
          // print(nums);
            i = (i+1)%n;
          }else{
            i = (i+1)%n;
            t++;
            
          }
          
        }
        for(i=0;i<n;++i){
          if(nums[i]==0){
            break;
          }
        }
        return i;
    }
};

int main(){

Solution so;
cout << so.LastRemaining_Solution(0, 0)<<endl;
// int i=0;
// int n=5;
// for(int j=0;j<10;++j){
//    i=(i+1)%n;
//    printf("%d ", i);
// }
// vector<int> nums(0, 0);
// cout << nums[0]<<endl;

}