/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 bool flag;
  int solve(TreeNode * root){
    if(root==NULL) return 0;
        int l=1+solve(root->left);
        int r=1+solve(root->right);
        if(abs(l-r)>1) flag=false;
    
        return max(l,r);
  }
    bool isBalanced(TreeNode* root) {
        flag=true;
         solve(root);
         return flag;
    }
};