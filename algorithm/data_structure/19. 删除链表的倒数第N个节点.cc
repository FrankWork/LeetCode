#include "../template.h"


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head, *fast=head;
        while(n){
          fast=fast->next;
          n--;
        }
        // 删除第一个节点
        if(fast==NULL) return head->next;

        while(fast->next){
          fast=fast->next;
          slow=slow->next;
        }
        // slow 是倒数第n个的前一个节点
        slow->next = slow->next->next;
        return head;
    }
};

int main(){
  ListNode n1(1), n2(2);
  n1.next = &n2;
  Solution so;
  ListNode * n= so.removeNthFromEnd(&n1, 2);
  printList(n);
}