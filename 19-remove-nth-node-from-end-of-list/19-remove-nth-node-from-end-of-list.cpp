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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        
        if(n==1 && head->next==NULL){
            return NULL;
        }
        
        ListNode* curr=head,*prv=head;    
        while(n-- && curr){
           curr=curr->next;
        }
        
        if(!curr){
            return head->next;
        }
        
        while(curr && curr->next){
            curr=curr->next;
            prv=prv->next;
        }
        
        ListNode* tmp=NULL;
        
        if(prv){
            tmp=prv->next;
            prv->next=prv->next->next;
            delete tmp;
        }
        return head;
    }
};
