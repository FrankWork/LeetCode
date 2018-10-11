#include "../template.h"


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if(!head)return head;
        ListNode *even_cur=NULL, *even_head=NULL, *cur;

        cur=head;
        while(cur && cur->next){
          // printf("%d ", cur->val);
          if(!even_head) {
            even_head=cur->next;
          }else{
            even_cur->next = cur->next;
          }
          even_cur = cur->next;
          cur->next = even_cur->next;
          even_cur->next = NULL;
          cur = cur->next;
        }
        // printf("\n");

        cur=head;
        while(cur && cur->next){
          cur=cur->next;
        }
        cur->next = even_head;
        return head;
    }
};


int main(){
  ListNode a1(1),a2(2),a3(3),a4(4),a5(5);
  a1.next=&a2;
  a2.next=&a3;
  a3.next=&a4;
  a4.next=&a5;

  Solution so;
  so.oddEvenList(&a1);
  printList(&a1);
}
