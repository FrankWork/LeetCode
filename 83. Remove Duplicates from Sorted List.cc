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
        ListNode *fast=head->next, *slow=head;
        while(fast!=NULL){
          if(fast->val==slow->val){
            slow->next=fast->next;
            fast=fast->next;
          }else{
            slow=slow->next;
            fast=fast->next;
          }
        }
        return head;
    }
};