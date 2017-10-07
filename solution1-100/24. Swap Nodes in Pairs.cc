/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values
in the list, only nodes itself can be changed.

Hide Tags Linked List
Show Similar Problems
*/
#include <iostream>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *left=head, *right=NULL, *t, *pre=NULL;

        if(left)right=left->next;
        //pre-> left->right->t
        //pre-> right->left->t
        while(right){
            if(pre==NULL) head = right;
            else pre->next = right;
            t = right->next;
            right->next = left;
            left->next = t;

            pre= left;
            left = t;
            if(left)right = left->next;
            else right=NULL;
        }
        return head;
    }
};
void print(ListNode *head){
    ListNode *cur = head;
while(cur){
        cout << cur->val<<",";
        cur=cur->next;
    }
cout <<endl;
}
int main(){
    ListNode *head = new ListNode(1), *cur = head;

    for(int i=2;i<5;i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    print(head);
    Solution so;
    cur = so.swapPairs(head);
    print(cur);
    return 0;
}
