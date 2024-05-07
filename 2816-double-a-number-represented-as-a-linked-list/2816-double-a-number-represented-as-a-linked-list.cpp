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
    ListNode* reverse(ListNode* curr){
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
    ListNode* doubleIt(ListNode* head) {
        ListNode * curr=head;
        curr=reverse(head);
        ListNode *t=curr;
        ListNode *prev;
        int carry=0,sum=0;
        while(t!=NULL){
            int x=(t->val*2+carry);
            int add=x%10;
            t->val=add;
            prev=t;
            carry=x/10;
            t=t->next;
        }
        if(carry>0){
            ListNode* temp=new ListNode(carry);
            prev->next=temp;
            prev=prev->next;
        }
        return reverse(curr);
    }
};