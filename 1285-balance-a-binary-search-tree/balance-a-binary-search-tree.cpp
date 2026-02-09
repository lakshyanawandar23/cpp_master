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
   void solve(TreeNode * root,vector<int>&v){
    if(root==NULL) return;
    solve(root->left,v);
      v.push_back(root->val);
    solve(root->right,v);
    return ;
   }
   TreeNode* tree(int l,int h,vector<int>&v){
    if(l>h) return NULL;
    int mid=(l+h)/2;
    TreeNode * temp=new TreeNode(v[mid]);
    temp->left=tree(l,mid-1,v);
    temp->right=tree(mid+1,h,v);
    return temp;
   }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        return tree(0,v.size()-1,v);
    }
};