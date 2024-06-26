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
    void dfs(TreeNode * root,vector<int>&v){
    if(root==NULL) return ;
     dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
        return ;
    }
    TreeNode * solve(vector<int>&v,int l,int h){
        if(l>h) return NULL;
        int mid=(l+h)/2;
        TreeNode * root=new TreeNode (v[mid]);
        root->left=solve(v,l,mid-1);
        root->right=solve(v,mid+1,h);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        dfs(root,v);
       return solve(v,0,v.size()-1);
    }
};