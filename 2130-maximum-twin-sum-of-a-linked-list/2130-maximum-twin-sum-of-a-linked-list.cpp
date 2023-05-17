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
    int pairSum(ListNode* head) {
        int ans=0,cnt=0,i=0;
        stack<ListNode*>s;
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            s.push(curr);
            curr=curr->next;
        }
        while(i<cnt/2){
            int sum=head->val+s.top()->val;
            s.pop();
            ans=max(ans,sum);
            i++;
            head=head->next;
        }
        return ans;
    }
};