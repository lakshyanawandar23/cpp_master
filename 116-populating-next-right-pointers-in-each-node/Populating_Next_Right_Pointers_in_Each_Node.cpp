/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution { // BFS based Solution (Iterative Version)
public:
    Node* connect(Node* root) {  // T.C. O(n) A.S. O(W+1) W is max-width of Tree
        if(!root){
            return root;
        }

        queue<Node*> q;
        q.push(root);
        Node* curr=NULL;
        while(q.empty()==false){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                Node* curr=q.front();
                if(q.front()->left){
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                if(i==sze-1){
                    curr->next=NULL;
                }
                q.pop();
                if(i<sze-1){
                    curr->next=q.front();
                }
            }
        }
       return root;
    }
};
