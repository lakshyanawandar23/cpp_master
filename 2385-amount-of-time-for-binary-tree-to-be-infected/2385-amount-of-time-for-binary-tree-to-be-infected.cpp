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
class Solution {  // T.C. O(n) and Auxilary Space O(h) for call Stack Best Solution
public:
    int res;
    int amountOfTime(TreeNode* root, int start) {
        res=-1;
        int dist=-1;
        solve(root,start,dist);
        return res;
    }
    
    int solve(TreeNode* root,int start,int &dist){
        if(!root){
            return 0;
        }
        
        if(root->val==start){
            int tmp=-1;
            res=max(res,max(solve(root->left,start,tmp),solve(root->right,start,tmp)));
            dist=0;
            return 1;
        }
        
        int ldist=-1,rdist=-1;
        
        int lh=solve(root->left,start,ldist);
        int rh=solve(root->right,start,rdist);

        if(ldist!=-1){
            dist=ldist+1;
            res=max(res,rh+dist);
        }
        
        if(rdist!=-1){
            dist=rdist+1;
            res=max(res,lh+dist);
        }
        
        return max(rh,lh)+1;
        
    }
    
    
};
