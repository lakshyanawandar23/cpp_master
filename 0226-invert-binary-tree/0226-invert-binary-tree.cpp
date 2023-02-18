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
    TreeNode* invertTree(TreeNode* root) {
       // TreeNode * r=new TreeNode(root->val);
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto p=q.front();
                q.pop();
                TreeNode* l=p->left;
                TreeNode* r=p->right;
                p->left=r;
                p->right=l;
                if(r){
                    q.push(r);
                }
                if(l){
                    q.push(l);
                }
            }
        }
        return root;
    }
};