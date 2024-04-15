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
    string ans;
  //  ans.append(8500,'z');
    void solve(TreeNode * root,string res){
        if(root==NULL) return ;
        if(root->left==NULL&&root->right==NULL) {
            res+=(root->val+'a');
            //cout<<res<<endl;
            reverse(res.begin(),res.end());
            ans=min(ans,res);
            res.pop_back();
            return ;
        }
        res+=(root->val+'a');
        solve(root->left,res);
        solve(root->right,res);
        res.pop_back();
        return ;
    }
    string smallestFromLeaf(TreeNode* root) {
        ans.append(8500,'z');
        solve(root,"");
        return ans;
    }
};