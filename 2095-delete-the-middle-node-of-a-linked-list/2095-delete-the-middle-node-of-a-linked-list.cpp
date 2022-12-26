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
class Solution { // Brute Force Solution
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head)return head;
        ListNode *ptr=head ,  *prv=head , *nd=nullptr;
        while(ptr && ptr->next)
        {
            nd=prv , prv=prv->next , ptr=ptr->next->next;
            if(ptr && ptr->next)
              nd=prv ,  prv=prv->next , ptr=ptr->next->next;
        }
        if(nd)
            nd->next=prv->next , delete prv;
        else return nullptr;
     return head;
    }
};
