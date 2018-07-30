#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
public:
    int TreeDepth(TreeNode* root)
    {
      if(root==NULL){
        return 0;
      }
      else if(root->left==NULL && root->right==NULL){
        return 1;
      }
      return max(TreeDepth(root->left), TreeDepth(root->right))+1;
    }
};

int main(){

}