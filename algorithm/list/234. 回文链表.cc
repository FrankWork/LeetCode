#include "../template.h"


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        /* 找到链表中点，将链表拆成两半，后半段反转顺序。

        找中点可以使用快慢指针，快指针走两步，慢指针走一步，快指针走到尾部时，慢指针走到中点。
        将后半部分入栈(或者链表原地反转)。
        */
       ListNode* fast=head, *slow=head, *cur;
       while(fast!=NULL && fast->next!=NULL){
         fast=fast->next->next;
         slow=slow->next;
       }

       stack<int> s;
       cur=slow;
       while(cur){
         s.push(cur->val);
         cur=cur->next;
       }

       cur=head;
       while(cur!=slow){
         if(cur->val != s.top()) return false;
         cur=cur->next;
         s.pop();
       }
      return true;
    }
};

