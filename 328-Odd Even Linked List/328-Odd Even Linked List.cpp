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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        if(!(head->next))return head;
        ListNode *ptr=head->next;
        ListNode *start=nullptr,*last=nullptr,*prv=nullptr,*tmp=head;
        while(ptr && ptr->next)
        {
            prv=ptr;
            ptr=ptr->next;
            if(ptr)
            {
                tmp->next=ptr;
                tmp=ptr;
                ptr=ptr->next;
            }
            if(!start)
                start=last=prv;
            else
                last->next=prv;
            last=prv;
        }
        if(start)tmp->next=start , last->next=ptr;
        return head;
    }
};
