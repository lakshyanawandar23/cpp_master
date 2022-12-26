/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // T.C. O(1) and A.S. O(1)
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp=node->next;
        if(node && node->next){
            node->val=node->next->val;
            node->next=node->next->next;
        }
        if(tmp)delete tmp;
        return;
    }
};
