#include "../template.h"


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res=0;
        if(!root)return res;

        if(root->val==sum)res++;
        


        return res;
    }
};

