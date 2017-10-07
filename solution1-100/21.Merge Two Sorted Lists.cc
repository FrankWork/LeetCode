/*
Merge two sorted linked lists and return it as a new list. The new list should be
made by splicing together the nodes of the first two lists.

Hide Tags Linked List
Hide Similar Problems (H) Merge k Sorted Lists (E) Merge Sorted Array (M) Sort List

*/
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list. */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2==NULL) return l1;
        if(l1==NULL) return l2;
        ListNode *head, *cur;

        if(l1->val<=l2->val){
            head= l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        cur = head;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                cur->next= l1;
                cur = cur->next;
                l1 = l1->next;
            }else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        while(l1!=NULL){
            cur->next= l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }

        l1=l2=NULL;
        return head;
    }
};
int main(){
    Solution so;
    ListNode *l1=new ListNode(0),*l2=new ListNode(2),*cur;

    cur = l1;
    for(int i=1;i<=5;i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = l1;
    while(cur!=NULL){
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    cout <<endl;
    cur = l2;
    for(int i=3;i<=7;i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = l2;
    while(cur!=NULL){
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    cout <<endl;
    cur = so.mergeTwoLists(l1,l2);
    while(cur!=NULL){
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    return 0;
}
