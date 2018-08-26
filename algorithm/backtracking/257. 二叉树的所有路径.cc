#include "../template.h"


/**
 * Definition for a binary tree node.
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        /* 根节点dfs到叶节点， 只要按照顺序遍历，就不用记录已访问节点
        */
       vector<string> res;
       dfs(root, res, "");
       return res;
    }
    void dfs(TreeNode* root, vector<string>& res, string tmp){
      if(root==NULL) return;
      

      if(tmp.length()!=0) 
          tmp+="->";
      tmp+=to_string(root->val);

      // cout<<root->val<<" " <<tmp<<endl;

      if(root->left==NULL && root->right==NULL){
        res.push_back(tmp);
        return;
      }

      if(root->left) dfs(root->left, res, tmp);
      if(root->right) dfs(root->right, res, tmp);
      
    }
};


int main(){
  Solution so;
  TreeNode n1(1), n2(2), n3(3), n5(5);
  n1.left = &n2;
  n1.right = &n3;
  n2.right=&n5;

  vector<string> res = so.binaryTreePaths(&n1);
  print(res);
}