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
        ListNode * h2=new ListNode(-1);
        ListNode * curr=h2;
        while(head!=NULL){
     if(mp.find(head->val)==mp.end()){
         ListNode * temp=new ListNode(head->val);
         curr->next=temp;
         curr=curr->next;
     }
            head=head->next;
        }
        return h2->next;
    }
};