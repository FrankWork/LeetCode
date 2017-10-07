/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Hide Tags Linked List
Hide Similar Problems (M) Swap Nodes in Pairs

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2) return head;

        ListNode *iter=head,*bg,*ed,*pre = NULL;
        while(iter){
            bg = iter;//begin pointer of k group
            int i=0;
            for(;i<k;i++){
                if(!iter)
                    break;
                iter = iter->next;
            }
            ed = iter;//end pointer of k group

            if(i==k){//reverse k group
               /*
                if(bg==head)head = reverse(bg,ed);
                else pre->next = reverse(bg,ed);
                bg->next = ed;
                pre = bg;*/
                ListNode *cur = bg,*t,*h=NULL;
                while(cur!=ed){
                    t = cur->next;
                    cur->next = h;
                    h = cur;
                    cur = t;
                }
                if(bg==head)head = h;
                else pre->next = h;
                bg->next = ed;
                pre = bg;
            }
        }
        return head;
    }
   /* ListNode* reverse(ListNode *head, ListNode *ed){
        ListNode *iter=head,*t,*pre=NULL;

        while(iter!=ed){
            t = iter->next;
            iter->next = pre;
            pre=iter;
            iter = t;
        }

        return pre;
    }
    ListNode* reverse(ListNode *head){
        ListNode *iter=head,*t,*pre=NULL;

        while(iter){
            t = iter->next;
            iter->next = pre;
            pre=iter;
            iter = t;
        }

        return pre;
    }*/
};
void print(ListNode *head){
    ListNode *cur = head;
    while(cur){
        cout <<cur->val<<"->";
        cur=cur->next;
    }
    cout <<endl;
}
int main(){
    Solution so;
    ListNode *head = new ListNode(1),*cur=head;
    for(int i=2;i<7;i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    print(head);

    print(so.reverseKGroup(head,3));
    return 0;
}
