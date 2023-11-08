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
    int cnt;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
    auto l=solve(root->left);
    auto r=solve(root->right);
        int s=root->val+l.first+r.first;
        int n=1+l.second+r.second;
        int avg=s/n;
        if(avg==root->val){
            cnt++;
        }
        return {s,n};
    }
    int averageOfSubtree(TreeNode* root) {
        cnt=0;
        solve(root);
        return cnt;
    }
};