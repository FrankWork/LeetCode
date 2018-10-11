#include "../template.h"


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        /* 
            先计算链表长度n, n/k为每部分的平均长度
        */
       int n=0;
       ListNode* cur=root;
       while(cur){
         cur=cur->next;
         ++n;
       }
       int avg = n/k;
       int mod = n%k;// 前mod个比剩下部分多一个元素

       vector<ListNode*> res(k, NULL);
       
       cur=root;
       for(int i=0;i<k && cur;++i){
         res[i] = cur;
         for(int j=0;j<avg-1 && cur;++j){
           cur=cur->next;
         }
         if(avg>0 && i<mod){
           cur=cur->next;
         }
         if(cur){
           ListNode* t=cur->next;
           cur->next=NULL;
           cur = t;
         }
       }

      return res;
    }
};

