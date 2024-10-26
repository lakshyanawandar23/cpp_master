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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode *,TreeNode *>>q;
        q.push({root,NULL});
        int sum=0,tot=0,curr=0;
        unordered_map<TreeNode* ,int>mp;
        mp[root]=0;
     while(!q.empty()){
         int k=q.size();
         curr=tot;
         tot=0;
         while(k--){
             sum=0;
             auto p=q.front();
             q.pop();
             if(p.first->left){
                 q.push({p.first->left,p.first});
                 sum+=p.first->left->val;
             }
             if(p.first->right){
                 q.push({p.first->right,p.first});
                 sum+=p.first->right->val;
             }
             mp[p.first]=sum;
             tot+=sum;
             p.first->val=curr-mp[p.second];
         }
     }
        return root;
    }
};