#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
      if(pHead==NULL || pHead->next==NULL){
        return pHead;
      }
      ListNode *p=pHead, *nH=NULL, *t;
      while(p!=NULL){
        t=p->next;
        p->next = nH;
        nH=p;
        p=t;
      }
      
      return nH;
    }
};
int main(){
  
  
  return 0;
}