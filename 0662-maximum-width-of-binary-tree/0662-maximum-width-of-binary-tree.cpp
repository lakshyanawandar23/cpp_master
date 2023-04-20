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
    int widthOfBinaryTree(TreeNode* root) {
       
      queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
      int ans=0;
        while(!q.empty()){
            int k=q.size();
           int l=INT_MAX,r=INT_MIN;
            while(k--){
         TreeNode* t=q.front().first;
        int idx=q.front().second;
          l=min(l,idx);
            r=max(r,idx);
    if(t->left){
        q.push({t->left,(long long int)2*idx+1});
        }
            if(t->right){
                q.push({t->right,(long long int)2*idx+2});
                }
            q.pop();
            }
            ans=max(ans,(r-l)+1);
            }
        return ans;
    }
};