#include "../template.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      /* 用栈来转换链表，让低位在最上部分
      */
        stack<int> s1, s2;
        while(l1){
          s1.push(l1->val);
          l1 = l1->next;
        }
        while(l2){
          s2.push(l2->val);
          l2 = l2->next;
        }
        ListNode *head=NULL;
        int carry=0;
        while(!s1.empty() && !s2.empty()){
          carry += s1.top() + s2.top();
          ListNode *cur = new ListNode(carry%10);
          carry /=10;

          cur->next=head;
          head=cur;

          s1.pop();
          s2.pop();
        }
        while(!s1.empty()){
          carry += s1.top();
          ListNode*cur = new ListNode(carry%10);
          carry/=10;
          
          cur->next=head;
          head=cur;
          s1.pop();
        }
        while(!s2.empty()){
          carry += s2.top();
          ListNode* cur = new ListNode(carry%10);
          carry/=10;

          cur->next=head;
          head=cur;
          s2.pop();
        }
        if(carry){
          ListNode*cur = new ListNode(carry);
          cur->next=head;
          head=cur;
        }
        
        return head;
    }
};

