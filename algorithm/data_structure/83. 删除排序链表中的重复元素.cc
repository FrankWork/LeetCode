#include "../template.h"



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;

        ListNode* next=head->next;
        while(next!=NULL && head->val==next->val){
          next = next->next;
        }
        head->next = deleteDuplicates(next);
        return head;
    }
};