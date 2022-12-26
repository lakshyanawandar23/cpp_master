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
    int mod;
    long long int mx;
    TreeNode* nd;
    int maxProduct(TreeNode* root) {
        mx=INT_MIN;
        nd=root;
        mod=1000000007;
        solve(root);
        return mx;
    }
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        long long lft=solve(root->left);
        long long int rght=solve(root->right);
        long  long int upr=func(nd,root)+root->val;
        int tmp1=((lft+upr)*(rght))%mod;
        int tmp2=((rght+upr)*lft)%mod;
        int tmpMax=max(tmp1,tmp2);
        if(tmpMax>mx){
            mx=tmpMax;
        }
        return lft+rght+root->val;
    }
    int func(TreeNode* root,TreeNode* node){
        if(!root || root==node){
            return 0;
        }
        return func(root->left,node)+func(root->right,node)+root->val;
    }
};
