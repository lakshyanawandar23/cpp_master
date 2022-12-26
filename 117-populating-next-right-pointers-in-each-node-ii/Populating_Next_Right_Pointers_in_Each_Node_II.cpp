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

class Solution {  // Iterative Solution T.C.  O(n)  A.S. O(w+1) where w is width of tree
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false){
            int sze=q.size();
            for(int i=0;i<sze;i++){
                Node* curr=q.front();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                q.pop();
                if(i<sze-1){
                    curr->next=q.front();
                }
                else if(i==sze-1){
                    curr->next=NULL;
                }
            }
        }
        return root;
    }
};
