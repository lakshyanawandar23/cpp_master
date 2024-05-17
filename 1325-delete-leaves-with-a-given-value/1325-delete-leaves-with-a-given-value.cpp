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
    TreeNode * solve(TreeNode *root,int &t){
        if(root==NULL) return NULL;
        if(root->left==NULL&&root->right==NULL&&root->val==t) return NULL;
        root->left=solve(root->left,t);
        root->right=solve(root->right,t);
        if(root->left==NULL&&root->right==NULL&&root->val==t) return NULL;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        return solve(root,t);
    }
};