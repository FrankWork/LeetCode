#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head==NULL) return NULL;
      int target=head->val;
      
      ListNode guard(0);
      guard.next = head;
      ListNode *fast=head->next, *slow=head, *valid=&guard;

      if(fast!=NULL && fast->val==slow->val){
        guard.next=fast->next;
        slow=&guard;
        fast=fast->next;
      }
      while(fast!=NULL){
        if(fast->val==target){
          valid->next=fast->next;
          slow=valid;
          fast=fast->next;
        }else{
          target=fast->val;
          valid=slow;
          slow=fast;
          fast=fast->next;
        }
      }
      return guard.next;
    }
};

void print(ListNode *head){
  ListNode *cur;
  cur = head;
  while(cur!=NULL){
    printf("%d->", cur->val);
    cur = cur->next;  
  }
  printf("NULL\n");
}

int main(){
  vector<int> nums{
    1, 2, 3, 3, 4, 4, 5 //1->2->5.
    // 1, 1, 1, 2, 3 //2->3.
  };

  ListNode *head, *node, *cur;
  for(int i=0;i<nums.size();++i){
    node = new ListNode(nums[i]);
    if(i==0){
      head=node;
    }else{
      cur->next = node;
    }
    cur = node;
  }
  print(head);
  Solution so;
  head = so.deleteDuplicates(head);
  print(head);
}