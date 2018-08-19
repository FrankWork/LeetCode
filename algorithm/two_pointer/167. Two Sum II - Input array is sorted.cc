#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    vector<int> twoSum(vector<int>& a, int k){
        /* 双指针
            l 从左侧开始移动
            r 从右侧开始移动
            类似二分查找
        */
       int n=a.size();
       int l=0, r=n-1;
       vector<int> res(2);
       while(l<r){
           int t=a[l]+a[r];
           if(t==k){
               res[0]=l+1;
               res[1]=r+1;
               break;
           }else if(t<k)l++;
           else r--;
       }
       return res;
    }
};
main(){
    Solution so;
    vector<int> a{2, 7, 11, 15};
    vector<int> res = so.twoSum(a, 9);
    printf("%d %d\n", res[0], res[1]);
    // cout << so.twoSum(a, 9) << endl;
}