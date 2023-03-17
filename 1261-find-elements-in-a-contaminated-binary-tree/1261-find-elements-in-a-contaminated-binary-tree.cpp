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
class FindElements {
public:
      unordered_map<int,int>m;
    void dfs(TreeNode* root,int v,unordered_map<int,int>&m){
        if(root==NULL){
            return ;
        }
        root->val=v;
        m[v]++;
        if(root->left){
            int res=(2*v)+1;
            dfs(root->left,res,m);
        }
        if(root->right){
            int res=2*v+2;
            dfs(root->right,res,m);
        }
    }
    FindElements(TreeNode* root) {
      m.clear();
        dfs(root,0,m);
    }
    
    bool find(int target) {
        if(m.find(target)!=m.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */