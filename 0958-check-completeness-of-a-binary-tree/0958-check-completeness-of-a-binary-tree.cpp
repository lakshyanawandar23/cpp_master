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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
         bool  flag=false;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto p=q.front();
                q.pop();
                if(p->left==NULL){
                    flag=true;
                }
                if(p->left){
                    if(flag){
                        return false;
                    }
                    else{
                    q.push(p->left);
                    }
                }
                if(p->right==NULL){
                    flag=true;
                }
                if(p->right){
                    if(flag){
                        return false;
                    }
                    else{
                        q.push(p->right);
                    }
                }
            }
        }
        return true;
    }
};