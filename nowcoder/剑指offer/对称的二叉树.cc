#include "template.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* root)
    {
    /* 对称： 
        根节点为空
        根节点非空：比较左右子树

    1
  2   2
3  4 4  3
    */
      if(root==NULL){
        return true;
      }
      return dfs(root->left, root->right);
    }
    bool dfs(TreeNode *left, TreeNode* right){
      if(left==NULL && right==NULL)
        return true;
      
      if((left!=NULL && right==NULL) || (left==NULL && right!=NULL))
        return false;
      
      if(left->val==right->val)
        return dfs(left->left, right->right) && dfs(left->right, right->left);

      return false;
      
    }
};


int main(){

}

