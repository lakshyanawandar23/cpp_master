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
 
class Solution { // T.C. O(n^2)  A.S. O(h)
public:
    int preind;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preind=0;
        return makeTree(preorder,inorder,0,preorder.size()-1);
    }
    
    TreeNode* makeTree(vector<int>& preorder,vector<int>& inorder,int is,int ie){  // O(n^2) T.C. O(h) for call stacks
        if(is>ie){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(preorder[preind++]);
        
        int inInd;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                inInd=i;
                break;
            }
        }
        
        
        
        root->left=makeTree(preorder,inorder,is,inInd-1);
        root->right=makeTree(preorder,inorder,inInd+1,ie);
        return root;
    }
    
};
*/

class Solution {  // T.C. O(n) and A.S. O(h)+O(n) O(h) for DFS(call stack) and O(n) for Hashmap
public:
    int preind;
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preind=0;
        for(int i=0;i<inorder.size();i++){ // O(n)
            mp[inorder[i]]=i;
        }
        return makeTree(preorder,inorder,0,preorder.size()-1);
    }
    
    TreeNode* makeTree(vector<int>& preorder,vector<int>& inorder,int is,int ie){  // O(n^2) T.C. O(h) for call stacks
        if(is>ie){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(preorder[preind++]);
        
        
        int inInd=mp[root->val];
        
        
        root->left=makeTree(preorder,inorder,is,inInd-1);
        root->right=makeTree(preorder,inorder,inInd+1,ie);
        return root;
    }
    
};
