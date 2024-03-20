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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt=0;
        ListNode * prev=NULL;
        ListNode * next=NULL;
        ListNode * curr=list1;
        ListNode * next1=list2;
        while(next1->next!=NULL){
            next1=next1->next;
        }
        while(curr!=NULL){
            cnt++;
            if(cnt==a){
                prev=curr;
            }
            if(cnt==b+2){
                next=curr;
                break;
            }
            curr=curr->next;
        }
        prev->next=list2;
        next1->next=next;
        return list1;
    }
};