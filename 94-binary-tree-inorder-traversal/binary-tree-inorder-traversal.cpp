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

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        solve(root,inOrder);
        return inOrder;
    }
    
    void solve(TreeNode* root,vector<int>& inOrder){
        if(!root){
            return;
        }
        
        solve(root->left,inOrder);
        inOrder.push_back(root->val);
        solve(root->right,inOrder);
    }
    
};
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> stk;
        vector<int> inorder;
        if(!root)return inorder;
        TreeNode* curr=root;
        
        while(curr || stk.empty()==false){
            while(curr){
                stk.push(curr);
                curr=curr->left;
            }
            curr=stk.top()->right;
            inorder.push_back(stk.top()->val);
            stk.pop();
        }
        
        return inorder;
    }
};
