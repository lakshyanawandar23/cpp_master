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
    ListNode* modifiedList(vector<int>& num, ListNode* head) {
     unordered_map<int,int>mp;
        for(auto it:num){
            mp[it]++;
        }
        ListNode *h1=NULL;
        ListNode * prev=h1; 
        ListNode * curr=head;
        while(curr!=NULL){
     if(mp.find(curr->val)!=mp.end()){
         if(prev!=NULL){
    prev->next=NULL;
         }
         ListNode *next=curr->next;
         curr->next=NULL;
         delete(curr);
         curr=next;
     }
            else {
                if(prev!=NULL){
              prev->next=curr;
                prev=prev->next;
                }
                else {
                    prev=curr;
                }
                curr=curr->next;
            }
            if(prev!=NULL&&h1==NULL){
                h1=prev;
            }
        }
        return  h1 ;
    }
};