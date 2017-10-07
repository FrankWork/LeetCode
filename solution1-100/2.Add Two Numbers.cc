#include <iostream>
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
 };
class Solution {
public:
    /// the solution function
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *current, *tempNode;
        int val = 0, n = 0;

        while(l1!=NULL && l2 != NULL){
            val += l1->val + l2->val;
            tempNode = new ListNode(val%10);
            val /= 10;
            if(n ==0){
                head = tempNode;
                current = head;
            }else{
                current->next = tempNode;
                current = current->next;
            }
            l1=l1->next;
            l2=l2->next;
            ++n;
        }
        while(l1!=NULL){
            val += l1->val;
            tempNode = new ListNode(val%10);
            val /= 10;
            if(n ==0){
                head = tempNode;
                current = head;
            }else{
                current->next = tempNode;
                current = current->next;
            }
            ++n;
            l1=l1->next;
        }
        while(l2!=NULL){
            val += l2->val;
            tempNode = new ListNode(val%10);
            val /= 10;
            if(n ==0){
                head = tempNode;
                current = head;
            }else{
                current->next = tempNode;
                current = current->next;
            }
            ++n;
            l2=l2->next;
        }
        while(val!=0){
            tempNode = new ListNode(val%10);
            val /= 10;
            current->next = tempNode;
            current = current->next;
            ++n;
        }
        return head;
    }
};
void test(int a1[], int a2[], int n1, int n2, int testN);
ListNode *getList(int arr[], int n);
void printList(ListNode *l);
int main()
{
    int n1=9,n2=9;
    int a1[] = {1,2,3,4,5,6,7,8,9};
    int a2[] = {1,2,3,4,5,6,7,8,9};
    test(a1,a2,n1,n2, 0);///

    int n11=3,n12=3;
    int a11[] = {2,4,3};
    int a12[] = {5,6,4};
    test(a11,a12,n11,n12, 1);///708

    int n21=3,n22=9;
    int a21[] = {2,4,3};
    int a22[] = {1,2,3,4,5,6,7,8,9};
    test(a21,a22,n21,n22,2);///708

    int n41=1,n42=9;
    int a41[] = {0};
    int a42[] = {1,2,3,4,5,6,7,8,9};
    test(a41,a42,n41,n42,4);///708
    return 0;
}
void test(int a1[], int a2[], int n1, int n2, int testN){
    ///No delete
    std::cout << "test#"<<testN << ":\n";
    ListNode *head, *l1,*l2;
    Solution s;
    l1 = getList(a1, n1);
    l2 = getList(a2, n2);
    printList(l1);
    printList(l2);
    head = s.addTwoNumbers(l1,l2);
    printList(head);
    std::cout << std::endl;
}

ListNode *getList(int arr[], int arrLength){
    ListNode *head, *tempNode, *current;

    for(int i=0;i< arrLength;++i){
        tempNode = new ListNode(arr[i]);
        if(i==0){
            head = tempNode;
            current = head;
        }else{
            current->next = tempNode;
            current = current->next;
        }
    }
    return head;
}
void printList(ListNode *current){
    while(current != NULL){
        std::cout << current->val <<" ";
        current=current->next;
    }
    std::cout << std::endl;
}
