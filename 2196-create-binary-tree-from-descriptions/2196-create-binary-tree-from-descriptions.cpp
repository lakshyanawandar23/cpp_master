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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,TreeNode *>mp;
        unordered_set<int>s;
        for(int i=0;i<d.size();i++){
            int p=d[i][0];
            int c=d[i][1];
            TreeNode *root;
            TreeNode *child;
            if(mp.find(p)==mp.end()){
             //  cout<<p<<endl;
                root=new TreeNode(p);
                mp[p]=root;
            }
            else {
                root=mp[p];
             //   cout<<"hi"<<endl;
            }
            if(mp.find(c)==mp.end()){
                child=new TreeNode(c);
                mp[c]=child;
                s.insert(c);
              // cout<<c<<endl;
            }
            else{
             child=mp[c];
            s.insert(c);
            }
            if(d[i][2]==1){
                root->left=child;
            }
            else {
                root->right=child;
            }
        }
        for(auto it:mp){
        //    cout<<it.first<<" "<<it.second<<endl;
            if(s.find(it.first)==s.end()){
              return  it.second;
        }
        }
        return NULL;
    }
};