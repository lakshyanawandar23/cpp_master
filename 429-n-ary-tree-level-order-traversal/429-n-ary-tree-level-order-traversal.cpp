/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false){
            vector<int> ds;
            int sze=q.size();
            for(int i=0;i<sze;i++){
                ds.push_back(q.front()->val);
                int sz=q.front()->children.size();
                for(int i=0;i<sz;i++){
                    q.push(q.front()->children[i]);
                }
                q.pop();
            }
            res.push_back(ds);
        }
        return res;
    }
};