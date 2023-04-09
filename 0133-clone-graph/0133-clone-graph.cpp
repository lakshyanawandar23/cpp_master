/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,Node*copy,vector<Node*>&vis){
        vis[copy->val]=copy;
        for(auto v:node->neighbors){
            if(vis[v->val]==0){
                Node* t=new Node(v->val);
                copy->neighbors.push_back(t);
                dfs(v,t,vis);
            }
            else{
                copy->neighbors.push_back(vis[v->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        vector<Node*>vis(1000,0);
        if(node==NULL){
            return NULL;
        }
        Node* copy=new Node(node->val);
        dfs(node,copy,vis);
        return copy;
    }
};