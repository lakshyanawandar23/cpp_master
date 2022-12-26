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
class Solution { // T.C. O(n) A.S. O(n+h)
public:
    int postind;
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            mp[inorder[i]]=i;
        }
        postind=inorder.size()-1;
        return makeTree(inorder,postorder,0,postorder.size()-1);
    }
    
    TreeNode* makeTree(vector<int>& inorder,vector<int>& postorder,int is,int ie){
        if(is>ie){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(postorder[postind--]);
        
        int inInd=mp[root->val];
        
        root->right=makeTree(inorder,postorder,inInd+1,ie);
        root->left=makeTree(inorder,postorder,is,inInd-1);
        return root;
    }
    
};