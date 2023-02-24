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
    int ans;
    int solve(TreeNode * root,unordered_map<int,int>&m){
        if(root==NULL){
            return 0;
        }
        int l=0,r=0;
        l+=solve(root->left,m);
        r+=solve(root->right,m);
        int s=root->val+l+r;
        m[s]++;
        ans=max(ans,m[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>m;
        ans=0;
        solve(root,m);
        vector<int>v;
        for(auto it:m){
            if(it.second==ans){
                v.push_back(it.first);
            }
        }
        return v;
    }
};