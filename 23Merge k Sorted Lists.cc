/*
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

Hide Tags Divide and Conquer Linked List Heap
Hide Similar Problems (E) Merge Two Sorted Lists

*/
#include <iostream>
#include <vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists.begin(),lists.end());
    }
private:
    ListNode* mergeKLists(vector<ListNode*>::iterator beg, vector<ListNode*>::iterator ed) {
        int sz = ed - beg;
        ListNode *head;
        switch(sz){
        case 0: head= NULL;break;
        case 1: head=  *beg;break;
        case 2: head=  mergeTwoLists(*beg, *(beg+1));break;
        default:
            int m = sz/2;
            head = mergeTwoLists(mergeKLists(beg,beg+m), mergeKLists(beg+m, ed));
        }

        return head;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode beforeHead(0), *cur=&beforeHead;

        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next= l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1)cur->next= l1;
        if(l2)cur->next = l2;
        return beforeHead.next;
    }

};

void test_func(){
    Solution so;
    ListNode *l1=new ListNode(0),*l2=new ListNode(2),*cur;
    ListNode *l3 = new ListNode(5);

    cur = l1;
    for(int i=1;i<=5;i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = l1;

    cur = l2;
    for(int i=3;i<=7;i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = l2;

    cur = l3;
    for(int i=7;i<=20;i+=2){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = l3;

    vector<ListNode*> vl;
    vl.push_back(l1);
    vl.push_back(l2);
    vl.push_back(l3);
    vl.push_back(NULL);
    cur = so.mergeKLists(vl);

    while(cur!=NULL){
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    cout<<endl;

}
void test_efficiency(){

}
int main(){
test_func();
    return 0;
}
