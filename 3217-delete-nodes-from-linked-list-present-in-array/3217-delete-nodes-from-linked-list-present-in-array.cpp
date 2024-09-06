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
        ListNode *prev;
        ListNode  *next;
        ListNode * h1=new ListNode(-1);
        ListNode * curr=head;
        prev=h1;
        while(curr!=NULL){
            if(mp.find(curr->val)!=mp.end()){
                next=curr->next;
                prev->next=next;
                delete(curr);
                curr=next;
            }
            else {
                prev->next=curr;
                prev=curr;
                curr=curr->next;
            }
        }
        return h1->next;
    }
};