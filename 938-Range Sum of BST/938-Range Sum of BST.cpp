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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        queue<TreeNode*> q;
        if(!root){
            return ans;
        }
        q.push(root);
        bool flag=true;
        while(q.empty()==false){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                TreeNode* curr=q.front();
                if(curr->val<=high && curr->val>=low){
                    ans+=curr->val;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                q.pop();
            }
        }
        return ans;
    }
};
