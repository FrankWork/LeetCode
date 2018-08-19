#include "template.h"

class Solution {
public:
    void sortColors(vector<int>& a) {
        /* 快排思想, 
              i 0的待插入位置
              j 1的待插入位置
              k 2的待插入位置
           对j进行遍历，方便与i, k交换数据
        */
       int i=0,j=0,k=a.size()-1;
       while(j<=k){
         if(a[j]==0) swap(a[i++], a[j++]);
         else if(a[j]==2) swap(a[j], a[k--]);// j不递增, 换过来的元素不一定为1
         else j++;
       }
    }
};

int main(){
    // vector<int> a{2,0,2,1,1,0};
    // vector<int> a{2,0,1};
    vector<int> a{1,2,0};
    
    
    Solution so;
    so.sortColors(a);
    print(a);
}