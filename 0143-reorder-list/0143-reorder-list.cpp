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
    ListNode * solve(ListNode* curr){
        ListNode * prev=NULL;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        //finding middle node;
        ListNode * slow=head;
        ListNode *fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr2=slow->next;
        slow->next=NULL;
        curr2=solve(curr2);
        ListNode * next;
        ListNode * next1;
        while(curr2!=NULL){
            next=curr->next;
            ListNode * t=new ListNode(curr2->val);
            curr->next=t;
            t->next=next;
            next1=curr2->next;
            //curr2->next=NULL;
            curr=next;
            curr2=next1;
        }
        return ;
    }
};