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
  ListNode* rev(ListNode* head){
      ListNode* prev=NULL;
      ListNode* next;
      ListNode* curr=head;
      while(curr!=NULL){
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
          }
      return prev;}
    ListNode* reverseBetween(ListNode* head, int l, int r) {
       ListNode* curr=head;
        ListNode* prev=NULL;
      if(l==r){
          return head;}
        int k=l-1;
        while(k--){
            prev=curr;
            curr=curr->next;}
        if(prev!=NULL){
        prev->next=NULL;}
        ListNode* a=curr;
      ListNode* b=NULL;
    int ans=r-l;
  curr=curr->next;
        while((ans--)&&curr!=NULL){
            b=curr;
            curr=curr->next;}
        b->next=NULL;
        ListNode* temp=rev(a);
        if(prev!=NULL){
       prev->next=temp;}
        a->next=curr;
        if(l==1){
            return temp;}
        else {
            return head;}
    }
};