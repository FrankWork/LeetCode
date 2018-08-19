#include "template.h"

/**
 * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
            使用两个指针，快指针移动两个位置，慢指针移动一个位置
            若有环，在两指针到达结尾前，快慢指针一定会相遇
            两指针初始位置相同
            h->
            h->a
            h->a->b
        */

       ListNode* f=head, *s=head;
       while(s!=NULL && f!=NULL && s->next!=NULL && f->next->next!=NULL){
           if(f==s)return true;
           s=s->next;
           f=f->next->next;
       }
       return false;
    }
};

int main(int argc, char const *argv[])
{
    ListNode x(1);
    Solution so;
    cout << so.hasCycle(&x)<<endl;
    return 0;
}


