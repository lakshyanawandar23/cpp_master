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
class Solution {  // O(H) T.C.  O(n) A.S. O(H) (call stack auxilary space) DFS 
public:
    int cnt;
    int goodNodes(TreeNode* root) {
        cnt=0;
        solve(root,INT_MIN);
        return cnt;
    }

    void solve(TreeNode* root,int maxVal){
        if(!root){
            return;
        }

        if(root->val>=maxVal){
            cnt++;
            maxVal=root->val;
        }

        solve(root->left,maxVal);
        solve(root->right,maxVal);

        return;
    }

};
