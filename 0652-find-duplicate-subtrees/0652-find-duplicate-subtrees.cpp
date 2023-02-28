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
    string solve(unordered_map<string,int>&m,TreeNode* root,string r,vector<TreeNode*>&ans){
        if(root==NULL){
            return "#";
        }
        string left="",right="";
         left+=solve(m,root->left,r,ans);
         right+=solve(m,root->right,r,ans);
        string o=to_string(root->val)+"%";
        o+=left+"%";
        o+=right;
        if(m[o]==1){
            ans.push_back(root);
        }
        m[o]++;
        return o;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>m;
        vector<TreeNode*>ans;
        solve(m,root," ",ans);
        return ans;
    }
};