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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * root=new ListNode(-1);
        ListNode * r=root;
        ListNode * curr=head;
        int sum=0;
        while(curr!=NULL){
            if(curr->val==0){
                if(sum>0){
                ListNode *t=new ListNode(sum);
                    r->next=t;
                    r=t;
                }
                sum=0;
            }
            else {
               sum+=curr->val; 
            }
            curr=curr->next;
        }
        return root->next;
    }
};