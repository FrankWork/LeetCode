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
        vector<vector<int> > Print(TreeNode* root) {
            vector<vector<int>> res;
            queue<TreeNode*> q;
            if(root!=NULL)
              q.push(root);
            
            while(!q.empty()){
              int n=q.size();
              vector<int> tmp(n);
              for(int i=0;i<n;++i){
                TreeNode *node=q.front();
                q.pop();
                tmp[i]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
              }
              res.push_back(tmp);
            }
            
            return res;
        }
    
};
