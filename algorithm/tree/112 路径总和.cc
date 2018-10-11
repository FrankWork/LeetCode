#include "../template.h"


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        if(sum==root->val && !root->left && !root->right){
          return true;
        }
        if(hasPathSum(root->left, sum-root->val)){
          return true;
        }
        if(hasPathSum(root->right, sum-root->val)){
          return true;
        }
        return false;
    }
};