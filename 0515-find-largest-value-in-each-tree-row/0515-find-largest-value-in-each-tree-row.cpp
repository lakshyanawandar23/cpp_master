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
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL) return v;
        while(!q.empty()){
            int k=q.size(),ans=INT_MIN;
            while(k--){
        auto p=q.front();
              q.pop();
                ans=max(ans,p->val);
            if(p->left){
                q.push(p->left);
            }
                if(p->right){
                    q.push(p->right);
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};