#include "../template.h"


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter=0;
        depth(root);
        return diameter;
    }
    int depth(TreeNode* root){
      if(!root)return 0;
      int l=depth(root->left);
      int r=depth(root->right);
      diameter = max(diameter, l+r);
      return max(l, r)+1;
    }
    int diameter;
};
