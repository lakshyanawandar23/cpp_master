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
class Solution { // T.C. O(n) A.S. O(n)
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return ans;
        }
        vector<int> ds;
        
        solve(root,targetSum,ds);
        return ans;
    }
    
    void solve(TreeNode* root,int targetSum,vector<int> &ds){
        if(!root){
            return;
        }
        
        targetSum-=root->val;
        
        ds.push_back(root->val);
        
        if(root->left==root->right){
            if(targetSum==0){
                ans.push_back(ds);
            }
        }
        
        solve(root->left,targetSum,ds);
        solve(root->right,targetSum,ds);
        
        ds.pop_back();
        
    }
    
};
