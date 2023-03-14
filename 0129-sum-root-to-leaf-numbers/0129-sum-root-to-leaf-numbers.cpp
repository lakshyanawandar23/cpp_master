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
    void solve(TreeNode* root,int ans,int &sum){
        if(root->left==NULL&&root->right==NULL){
            ans=ans*10+root->val;
            sum+=ans;
            ans=ans/10;
            return ;
        }
        ans=ans*10+root->val;
        if(root->left!=NULL){
        solve(root->left,ans,sum);
        }
        if(root->right!=NULL){
        solve(root->right,ans,sum);
        }
        ans=ans/10;
        return ;
    }
    int sumNumbers(TreeNode* root) {
        int ans=0,sum=0;
    solve(root,ans,sum);
        return sum;
    }
};