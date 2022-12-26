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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0, mx = INT_MIN, mn = INT_MAX;
        solve(root, mx, mn, res);
        return res;
    }
    void solve(TreeNode* node, int mx, int mn, int& res) {
        if (!node) return;
        if (mx != INT_MIN) res = max(res, abs(mx - node->val));
        if (mn != INT_MAX) res = max(res, abs(node->val - mn));
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        solve(node->left, mx, mn, res);
        solve(node->right, mx, mn, res);
    }
};
