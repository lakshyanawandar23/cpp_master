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
    ListNode *reverse(ListNode *head){
        ListNode* prev=NULL;
        ListNode* next;
        ListNode* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=reverse(l1);
        ListNode* h2=reverse(l2);
        ListNode * ans=new ListNode(-1);
        ListNode *p=ans;
        int carry=0;
        while(h1!=NULL&&h2!=NULL){
            int u=h1->val;
            int v=h2->val;
            int  sum=(u+v+carry);
            int res=(sum%10);
            sum/=10;
            carry=sum%10;
            ListNode* temp=new ListNode(res);
            p->next=temp;
            p=p->next;
            h1=h1->next;
            h2=h2->next;
        }
        while(h1!=NULL){
            int sum=(h1->val+carry);
            int res=(sum%10);
            ListNode* temp=new ListNode(res);
            p->next=temp;
            p=p->next;
            sum/=10;
            carry=sum%10;
            h1=h1->next;
        }
          while(h2!=NULL){
            int sum=(h2->val+carry);
            int res=(sum%10);
            ListNode* temp=new ListNode(res);
            p->next=temp;
            p=p->next;
            sum/=10;
            carry=sum%10;
            h2=h2->next;
        }
        if(carry>0){
            ListNode* temp=new ListNode(carry);
            p->next=temp;
        }
        ListNode* head=ans->next;
        ans->next=NULL;
        ans=head;
      ListNode *q=reverse(ans);
        return q;
    }
};