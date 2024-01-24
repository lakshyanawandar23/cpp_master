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
    int cnt;
int v[10];
    void solve(TreeNode *root){
        if(root==NULL) return ;
        if(root->left==NULL&&root->right==NULL){
            v[root->val]++;
            int res=0;
    for(auto it:v){
        if(it%2!=0){
            res++;
        }
    }
            if(res<=1) cnt++;
            v[root->val]--;
            return ;
        }
        v[root->val]++;
        solve(root->left);
        solve(root->right);
        v[root->val]--;
        return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
        return cnt;
    }
};