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
    bool flag;
    bool hasPathSum(TreeNode* root, int targetSum) {
        flag=false;
        if(!root){
            return false;
        }
        solve(root,targetSum,0);
        return flag;
    }
    
    void solve(TreeNode* root,int targetSum,int target){
        if(!root){
            return;
        }
        
        target+=root->val;
        
        if(flag){
            return;
        }
        
        if(root->left==root->right){
            if(target==targetSum){
                flag=true;
            }
        }
        
        solve(root->left,targetSum,target);
        solve(root->right,targetSum,target);
        
    }
    
};
