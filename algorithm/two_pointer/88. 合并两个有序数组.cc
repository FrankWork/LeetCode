#include "template.h"

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        /*
            从尾部开始复制, 否则会覆盖a的内容
            使用归并排序中合并数组的思想，需要三个指针，
                i: a的指针
                j: b的指针
                k: 存储位置的指针

        */
       int i=m-1, j=n-1;
       int k=m+n-1;
       while(i>=0 && j>=0){
           if(a[i]>b[j]){
               a[k--]=a[i--];
           }else{
               a[k--]=b[j--];
           }
       }
       while(i>=0){
           a[k--]=a[i--];
       }
       while(j>=0){
           a[k--]=b[j--];
       }
    }
};