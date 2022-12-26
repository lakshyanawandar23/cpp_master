/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution { // T.C. O(3h) A.S. O(3h)  Naive Solution
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;

        TreeNode* adrs=NULL;
        
        solve(root,v1,p);
        solve(root,v2,q);
        for(int i=0;i<v1.size() && i<v2.size()&& v1[i]==v2[i];i++){
            adrs=v1[i];
        }
        
        
        return adrs;
    }
    
    void solve(TreeNode* root,vector<TreeNode*> &v,TreeNode* q){
        if(!root){
            return;
        }
        
        v.push_back(root);
        
        if(root==q){
            return;
        }
        
        if(root->val<q->val){
            solve(root->right,v,q);
        }
        else{
            solve(root->left,v,q);
        } 
    }
};
*/

class Solution { //we use advantages of BST basically LCA in BST is that where one in smaller than root and other is greater than root 
public: // T.C. O(h) and A.S. O(h)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};