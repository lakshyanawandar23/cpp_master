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
    TreeNode* solve(int s,int e,vector<int>&v)
    {
        if(s>e){
            return NULL;
        }
       int m=(s+e)/2;
        TreeNode* root=new TreeNode(v[m]);
        root->left=solve(s,m-1,v);
        root->right=solve(m+1,e,v);
        return root;
    }
    void dfs(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return ;
        }
      dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        dfs(root,v);
        return solve(0,v.size()-1,v);
    }
};