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
    char* Serialize(TreeNode *root) {
        /*层次遍历树， 空节点用"#"表示， 节点间用" "分开
        */ 
        queue<TreeNode*> q;
        q.push(root);
        string buf;
        TreeNode* node;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                node = q.front();
                if(node){
                    buf+= to_string(node->val) + " ";
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    buf+="#";
                }
                q.pop();
            }
        }
        return strdup(buf.c_str());
    }
    TreeNode* Deserialize(char *str) {
        TreeNode * root=NULL, *node;
        if(str==NULL)return root;
        int idx=0;

        root = nextNode(str, idx);
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;++i){
                node = q.front();
                if(node){
                    node->left = nextNode(str, idx);
                    node->right=nextNode(str, idx);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                
                q.pop();
            }
            
        }
        return root;
    }
    TreeNode* nextNode(char *str, int &i){
        TreeNode* node=NULL;
        if(str[i]=='#') {
            i++;
            return node;
        }
        string s;
        while(str[i]!='\0' && str[i]!=' '){
            s+=str[i++];
        }
        // cout <<s<<endl;
        printf("x%sx\n", s.c_str());
        if(s.size()>0){
             node = new TreeNode(stoi(s));
             i++;
        }
           
        return node;
    }
};

int main(){
    Solution so;
  string s="#";
  char *p = strdup(s.c_str());
  TreeNode *root = so.Deserialize(p);
  
  TreeNode a(1), b(2), c(3);
  a.left=&b;
  a.right=&c;

  p = so.Serialize(&a);//1 2 3 ####
  printf("%s\n", p);
//   s="1";
//   p = strdup(s.c_str());
  root=so.Deserialize(p);
}