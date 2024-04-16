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
TreeNode * solve(TreeNode *root,int  &val,int  &d,int l,bool pos){
   // if(root==NULL) return NULL;   
    if(l==d) {
           TreeNode * t=new TreeNode(val);
        if(pos)
           t->left=root;
        else 
            t->right=root;
        //   t->right=root;
           return t;
       }
    if(root){
    root->left=solve(root->left,val,d,l+1,true);
    root->right=solve(root->right,val,d,l+1,false);
    }
    return root;
}
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        return solve(root,val,d,1,true);
    }
};