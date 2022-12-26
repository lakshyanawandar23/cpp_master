/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // T.C. O(n) and A.S O(h) for call stacks
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        
        TreeNode* nd1=lowestCommonAncestor(root->left,p,q);
        TreeNode* nd2=lowestCommonAncestor(root->right,p,q);
        
        if(nd1 && nd2){
            return root;
        }
        
        if(nd1){
            return nd1;
        }
        
        return nd2;
        
    }
};
