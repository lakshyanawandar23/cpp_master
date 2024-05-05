/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * next=node->next;
        ListNode * next1=node->next->next;
        swap(node->next->val,node->val);
        node->next=next1;
        delete(next);
        return ;
    }
};