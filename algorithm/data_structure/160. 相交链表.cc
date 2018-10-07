#include "../template.h"


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      /* 
        A:          a1 → a2
                          ↘
                            c1 → c2 → c3
                          ↗            
        B:     b1 → b2 → b3
        三段链表长度为a,b,c: a+c +b =b+c +a
        当链表a访问到最后一个节点后，让它从b链表开始访问
        当链表b访问到最后一个节点后，让它从a链接开始访问
        若两个链接有交点，则在交点相遇
        否则，两个链表同时到达末端
      */
     ListNode* a=headA, *b=headB;
     
     while(a!=b){
       a = (a==NULL)? headB: a->next;
       b = (b==NULL)? headA: b->next;
     }
          
     return a;
    }
};

