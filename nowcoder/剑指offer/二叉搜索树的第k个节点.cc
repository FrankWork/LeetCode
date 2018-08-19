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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {/*
        二叉搜索树的中序遍历结果，为排序结果，
        找出中序遍历的第k个节点
    */
        vector<TreeNode*> vec;
        inorder(pRoot, vec);
        if(k>vec.size() || k<=0)return NULL;
        
        return vec[k-1];
    }
    void inorder(TreeNode*pRoot, vector<TreeNode*> &vec){
        if(pRoot==NULL)return;
        inorder(pRoot->left, vec);
        vec.push_back(pRoot);
        inorder(pRoot->right, vec);
    }

    
};

int main(){

}