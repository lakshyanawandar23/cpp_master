/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse(ListNode *t){
        ListNode *next=NULL;
        ListNode *prev=NULL;
        ListNode *curr=t->next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
             curr=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        //it is a probelm of next greater element 
        stack<int>s;
    while(head!=NULL){
        while(!s.empty()&&s.top()<head->val){
            s.pop();
        }
        s.push(head->val);
        head=head->next;
    }
        ListNode *t=new ListNode(-1);
        ListNode * curr=t;
        while(!s.empty()){
            int x=s.top();
            s.pop();
            ListNode* y=new ListNode(x);
            curr->next=y;
            curr=curr->next;
        }
       return reverse(t);
    }
};