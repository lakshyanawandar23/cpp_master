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
 long long int ans;
 int mod=1e9+7;
    long long int solve(TreeNode* root){
        if(!root) return 0;
      long long   int sum=root->val;
      long long  int left=solve(root->left);
      long long  int right=solve(root->right);
        sum+=(left+right);
        return sum;
     }
   long long  int solve2(TreeNode* root,long long int sum){
        if(!root) return 0;
      long long int res=root->val;
      long long int l=solve2(root->left,sum);
      long long int r=solve2(root->right,sum);
      long long int left_sum=(sum-(res+l+r));
      long long int tot=(res+l+r);
       ans=max(ans,(left_sum*tot));
      // ans=ans%mod;
       return tot;
    }
    int maxProduct(TreeNode* root) {
       long long int tot_sum=solve(root);
        ans=0;
        solve2(root,tot_sum);
        return ans%mod;
    }
};