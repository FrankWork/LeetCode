#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* head){
  ListNode* cur;

  for(cur = head; cur != NULL; cur=cur->next){
      cout << cur->val << "->";
    }
    cout << "NULL\n";
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur=head, *newHead;
        int n=0;

        while(cur!=NULL){
          cur=cur->next;
          ++n;
        }
        // cout << n << '\n';
        if(n==0){return head;}
        k%=n;
        if(k==0){return head;}

        cur=head;
        for(int i=0;i<n-k-1;++i){
          cur=cur->next;
        }
        // cout << cur->val << '\n';

        newHead=cur->next;
        cur->next=NULL;


        for(cur=newHead;cur->next!=NULL;cur=cur->next){
        }
        cur->next=head;
        return newHead;
    }
};

int main(){
    ListNode *head, *cur, *newNode;
    for(int i=1;i<=5;++i){
      newNode = new ListNode(i);
      if(i==1){
        head = newNode;
        cur = newNode;
      }else{
        cur->next = newNode;
        cur = newNode;
      }
    }
    // head = new ListNode(1);
    
    print(head);

    Solution so;
    print(so.rotateRight(head, 5));
    // Given 1->2->3->4->5->NULL and k = 2,
    // return 4->5->1->2->3->NULL.
}