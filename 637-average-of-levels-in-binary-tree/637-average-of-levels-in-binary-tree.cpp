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
    vector<double> averageOfLevels(TreeNode* root) { // O(n) BFS Aproach O(w) A.S.
        vector<double> avg;
        if(!root){
            return avg;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            int sze=q.size();
            double avgVal=0;
            for(int i=0;i<sze;i++){
                avgVal+=q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            avg.push_back(avgVal/sze);
        }
        return avg;
    }
};
