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
    int mx;
    int maxPathSum(TreeNode* root) {
        mx=INT_MIN;
        dfs(root);
        return mx;
    }
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int lft=max(0,dfs(root->left));
        int rght=max(0,dfs(root->right));
        mx=max(mx,lft+rght+root->val);
        return max(lft,rght)+root->val;
    }
};
