#include "../template.h"


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
         输入: 1->2->3->4->5->NULL
         输出: 5->4->3->2->1->NULL
        */
       if(head==NULL || head->next==NULL)
          return head;
       
       ListNode* cur=head;
       head = head->next;
       ListNode* newHead = reverseList(head);
       head->next=cur;
       cur->next = NULL;
       
       return newHead;
    }
   
};