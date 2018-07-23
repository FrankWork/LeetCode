#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
private:
    TreeNode* head=NULL, *pre=NULL;
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(root==NULL){
            return NULL;
        }
        Convert(root->left);
        root->left=pre;
        if(pre!=NULL){
            pre->right=root;
        }
        pre=root;
        if(head==NULL)head=root;
        Convert(root->right);
                
        return head;
    }
};

int main(){
  TreeNode a(2), b(3), c(4);
  b.left=&a;
  b.right=&c;

  Solution so;
  TreeNode* h=so.Convert(&b);
  while(h!=NULL){
    cout << h->val << " ";
    h=h->right;
  }
}