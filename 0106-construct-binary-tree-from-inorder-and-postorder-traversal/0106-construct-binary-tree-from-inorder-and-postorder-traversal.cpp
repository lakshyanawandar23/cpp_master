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
    int idx;
    TreeNode* solve(int s,int e,vector<int>&in,vector<int>&p){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(p[idx--]);
        int j=0;
        for(int i=0;i<in.size();i++){
            if(in[i]==root->val){
                j=i;
                break;
            }
        }
        root->right=solve(j+1,e,in,p);
       root->left=solve(s,j-1,in,p);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        idx=p.size()-1;
        return solve(0,in.size()-1,in,p);
    }
};