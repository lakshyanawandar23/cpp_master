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
        int cnt=0;
        ListNode *curr=head;
        ListNode * prev=NULL;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        curr=head;
        int t=cnt-n;
        if(t==0)  return head=head->next;
        while(t>0){
            t--;
            prev=curr;
            curr=curr->next;
        }
        if(curr->next!=NULL){
        prev->next=curr->next;
            curr=curr->next;
        }
        else {
            prev->next=NULL;
        }
        return head;
    }
};