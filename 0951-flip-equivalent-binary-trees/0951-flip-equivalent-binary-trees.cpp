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
    bool solve(TreeNode * root1,TreeNode * root2){
    if(root1==NULL&&root2==NULL) return true;
       if(root1!=NULL&&root2!=NULL){
           if(root1->val==root2->val){
            bool t1=solve(root1->left,root2->left)&&solve(root1->right,root2->right);
        bool t2=solve(root1->left,root2->right)&&solve(root1->right,root2->left);
               return t1||t2;
           }
           return false;
       }
        return false;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};