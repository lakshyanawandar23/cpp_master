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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode * curr=head;
        int n=0;
        while(curr!=NULL){
            curr=curr->next;
            n++;
        }
        vector<ListNode*>v;
        ListNode *temp=NULL;
        curr=head;
        if(n<=k){
            while(curr!=NULL){
                ListNode* t=new ListNode(curr->val);
                v.push_back(t);
                curr=curr->next;
                k--;
            }
            while(k--){
                v.push_back(temp);
            }
        }
        else{
            int mod=n%k;
            int mini=n/k;
            while(k>0){
             //   ListNode* start=curr;
          //      ListNode* next;
                ListNode *prev=new ListNode(-1);
                ListNode  *h=prev;
                int cnt=mini;
                if(mod>0){
                 cnt+=1;
                }
                while(curr!=NULL&&cnt>0){
                    cnt--;
                 //   cout<<curr->val<<endl;
                    prev->next=curr;
                    prev=prev->next;
                    curr=curr->next;
                }
                prev->next=NULL;
              //  cout<<h->next->val<<endl;
               //cout<<curr->val<<endl;
                v.push_back(h->next);
                mod--;
                k--;
            }
        }
        return v;
    }
};