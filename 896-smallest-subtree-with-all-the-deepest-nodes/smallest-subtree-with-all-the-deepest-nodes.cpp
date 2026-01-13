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
 TreeNode* ans;
 int maxdepth;
  int solve(TreeNode* root,int d){
       maxdepth=max(maxdepth,d);
    if(root==NULL) return d;
 
    int l=solve(root->left,d+1);
    int r=solve(root->right,d+1);
    if(l==maxdepth&&r==maxdepth) ans=root;
    return max(l,r);
  }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};