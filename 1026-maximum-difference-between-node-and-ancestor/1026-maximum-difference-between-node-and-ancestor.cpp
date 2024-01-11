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
    void solve(TreeNode* root,int &ans,int a,int b){
        if(root==NULL){
   return ;
        }
      //  int a=INT_MIN,b=INT_MAX;
        a=max(a,root->val);
        b=min(b,root->val);
        ans=max(ans,abs(a-b));
        solve(root->left,ans,a,b);
        solve(root->right,ans,a,b);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0,a=INT_MIN,b=INT_MAX;
        solve(root,ans,a,b);
        return ans;
    }
};