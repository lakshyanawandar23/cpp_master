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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        if(!root){
            return root;
        }
        while(curr && curr->val!=key){
            prev=curr;
            if(curr->val<key){
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        if(!curr){
            return root;
        }
        if(curr->left==NULL || curr->right==NULL){
            TreeNode *newCurr;
            if(curr->left){
                newCurr=curr->left;
            }
            else{
                newCurr=curr->right;
            }
            if(!prev){
                root=newCurr;
            }
            else if(prev->left==curr){
                prev->left=newCurr;
            }
            else{
                prev->right=newCurr;
            }
        }
        else{
            TreeNode *ptr=curr->left;
            TreeNode *node=curr->right;
            while(ptr->right){
                ptr=ptr->right;
            }
            ptr->right=node;
            if(!prev){
                root=curr->left;
            }
            else{
                if(prev->left==curr){
                    prev->left=curr->left;
                }
                else{
                    prev->right=curr->left;
                }
            }
        }
        return root;
    }
};
