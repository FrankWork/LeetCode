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
      /*
        层次遍历：偶数行要反转
        反转时不要用std::reverse，按下标 i或 n-1-i进行插入
      */
      vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root!=NULL)
          q.push(root);
        bool flag=false;// is reverse

        while(!q.empty()){
          int n=q.size();
          vector<int> tmp(n);
          for(int i=0;i<n;++i){
            TreeNode *node=q.front();
            q.pop();
            // tmp.push_back(node->val);
            if(flag)
              tmp[n-1-i]=node->val;
            else
              tmp[i]=node->val;
              

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
          }
          // if(flag)
          //   reverse(tmp.begin(), tmp.end());
          res.push_back(tmp);
          flag = !flag;
        }
        return res;
    }
    
};

int main(){

}