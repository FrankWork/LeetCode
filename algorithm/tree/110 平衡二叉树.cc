#include "../template.h"


class Solution {
public:
    bool isBalanced(TreeNode* root) {
      /* 任意子树的左右高度差都小于等于1
      */
      flag=true;
      maxDepth(root);
      return flag;
    }

    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(abs(l-r)>1) flag=false;
        return max(l, r)+1;
    }
    bool flag;
};


         