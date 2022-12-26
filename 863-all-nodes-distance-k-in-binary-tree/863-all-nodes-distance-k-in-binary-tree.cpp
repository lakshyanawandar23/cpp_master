/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // T.C. O(n) and A.S O(n)
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(!root){
            return res;
        }
        
        map<TreeNode*,TreeNode*> par; 
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                if(q.front()->left){
                    par[q.front()->left]=q.front();
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    par[q.front()->right]=q.front();
                    q.push(q.front()->right);
                }
                q.pop();
              }
        }
        
        map<TreeNode*,int> vis;
        queue<TreeNode*> q1;
        q1.push(target);
        int dist=0;
        while(q1.empty()==false && dist<k){
            int sze=q1.size();
            for(int i=0;i<sze;i++){
                if(q1.front()!=root && par[q1.front()] && vis[par[q1.front()]]==0){
                    q1.push(par[q1.front()]);
                }
                if(q1.front()->left && vis[q1.front()->left]==0){
                    q1.push(q1.front()->left);
                }
                if(q1.front()->right && vis[q1.front()->right]==0){
                    q1.push(q1.front()->right);
                }
                vis[q1.front()]=1;
                q1.pop();
            }
            dist++;
         }
        
        while(q1.empty()==false){
            res.push_back(q1.front()->val);
            q1.pop();
        }
        return res;
    }
};
