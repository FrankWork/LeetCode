/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
tags: Linked List Two Pointers

*/

#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=head,*tail=NULL,*t;

        //reserve the list
        while(cur!=NULL){
            t=cur->next;
            cur->next=tail;
            tail=cur;
            cur=t;
        }

        //find n-th node
        cur= tail;
        t = cur;
        while(--n){
             t=cur;
             cur=cur->next;
        }

        //delete cur
        if(cur!=tail){
            t->next=cur->next;
            //if(cur->next)
                //cout << cur->val<<endl;
        }else{
            tail=cur->next;
        }
        delete cur;

        //reserve the list
        cur = tail;
        head = NULL;
        while(cur!=NULL){
            t=cur->next;
            cur->next=head;
            head=cur;
            cur=t;
        }
        return head;
    }
};
int main(){
    Solution so;
    ListNode *head=new ListNode(1);
    ListNode *cur=head;
    for(int i=2;i<=5;i++){
        cur->next = new ListNode(i);
        cur=cur->next;
    }
    head=so.removeNthFromEnd(head,5);
    for(cur=head;cur!=NULL;cur=cur->next){
        cout<<cur->val<<"->";
    }

    cout<<endl;
    return 0;
}
