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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        int level=0;
        while(!q.empty()){
            int k=q.size(),i=0;
            vector<int>v;
            while(k--){
                auto p=q.front();
                q.pop();
                if(p->left){
                    q.push(p->left);
                    v.push_back(p->left->val);
                }
                if(p->right){
                    q.push(p->right);
                    v.push_back(p->right->val);
                }
                if(level%2!=0) p->val=ans[i]; i++;
            }
            level++;
            if(level%2!=0) reverse(v.begin(),v.end());
            ans=v;
        }
        return root;
    }
};