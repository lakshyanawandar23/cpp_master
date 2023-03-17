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
    long long int ans=0;
    void dfs(TreeNode* root){
        if(root==NULL){
            return ;
        }
        dfs(root->right);
        ans+=root->val;
            root->val=ans;
        dfs(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        ans=0;
        dfs(root);
        return root;
    }
};