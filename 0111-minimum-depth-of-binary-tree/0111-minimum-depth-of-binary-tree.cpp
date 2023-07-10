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
    int solve(TreeNode* root){
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        int ans=(min(solve(root->left),solve(root->right)))+1;
        return ans;
    }
    int minDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
         return solve(root);
    }
};