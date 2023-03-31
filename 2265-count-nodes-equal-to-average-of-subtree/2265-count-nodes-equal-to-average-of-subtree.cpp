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
        int sum=l.first+r.first+root->val;
        int size=l.second+r.second+1;
        if(sum/size==root->val){
            cnt++;
        }
        return {sum,size};
    }
    
    int averageOfSubtree(TreeNode* root) {
     cnt=0;
        solve(root);
        return cnt;
    }
};