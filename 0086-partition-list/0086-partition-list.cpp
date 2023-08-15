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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small=new ListNode(-1);
        ListNode *h=small;
        ListNode* l=new ListNode(-1);
        ListNode* h1=l;
        while(head!=NULL){
            ListNode* temp=new ListNode(head->val);
            if(head->val<x){
                small->next=temp;
                small=temp;
            }
            else{
                l->next=temp;
                l=temp;
            }
            head=head->next;
        }
        ListNode *p=h1->next;
        h1->next=NULL;
        h1=p;
        small->next=h1;
        return h->next;
    }
};