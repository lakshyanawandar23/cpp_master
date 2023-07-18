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
    ListNode* reverse(ListNode* head){
       ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
      while(curr!=NULL){
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;}
        return prev;
        }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     //l1=reverse(l1);
     //  l2=reverse(l2);
        ListNode* dummy=NULL;
        ListNode* a=NULL;
        int carry=0;
        while(l1!=NULL||l2!=NULL){
            int sum=0;
            sum+=l1==NULL?0:l1->val;
          sum+=l2==NULL?0:l2->val;
        
            sum=sum+carry;
          if(dummy==NULL){
          ListNode* temp=new ListNode(sum%10);
              dummy=temp;
              a=temp;}
            else {
                ListNode* temp=new ListNode(sum%10);
          a->next=temp;
                a=temp;}
            carry=sum/10;
        if(l1!=NULL){
                l1=l1->next;}
            if(l2!=NULL){
                l2=l2->next;}
            }
        if(carry!=0){
            ListNode* temp=new ListNode(carry);
           a->next=temp;
            a=a->next;}
       // dummy=reverse(dummy);
        return dummy;
    }
};