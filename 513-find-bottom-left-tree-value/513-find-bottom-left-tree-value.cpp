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
class Solution { // T.C. O(n) A.S. O(h)
public:
    int lvl;
    TreeNode* adrs;
    int findBottomLeftValue(TreeNode* root) {
        lvl=-1;
        adrs=NULL;
        
        if(!root){
            return -1;
        }
            
        solve(root,0);
        
        if(adrs){
            return adrs->val;
        }
        return -1;
    }
    
    void solve(TreeNode* root,int height){
      
        if(!root){
            return;
        }
        
        if(height>lvl){
            lvl=height;
            adrs=root;
        }
        
        solve(root->left,height+1);
        solve(root->right,height+1);
    }
    
};
