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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int k=q.size();
            vector<int>v;
            while(k--){
         TreeNode* t=q.front();
                q.pop();
             v.push_back(t->val);
            if(t->left){
                q.push(t->left);}
                if(t->right){
                    q.push(t->right);
                    }
              }
            if(i%2==0){
             if(v[0]%2==0){
                 return false;}
     for(int j=1;j<v.size();++j){
         if(v[j]%2==0||v[j]<=v[j-1]){
             return false;}
         }
                }
            else {
                if(v[0]%2!=0){
                    return false;}
      for(int j=1;j<v.size();++j){
          if(v[j]%2!=0||v[j]>=v[j-1]){
              return false;}
          }
                }
            i++;
            }
        return true;
          
             
    }
};