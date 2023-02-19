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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        queue<TreeNode*>q;
        if(root==NULL){
            return v;
        }
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int k=q.size();
            vector<int>ans;
            while(k--){
                auto p=q.front();
                q.pop();
                ans.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            if(cnt%2!=0){
                reverse(ans.begin(),ans.end());
            }
                v.push_back(ans);
            
            cnt++;
        }
        
        return v;
    }
};