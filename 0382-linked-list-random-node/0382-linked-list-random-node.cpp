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
    vector<int>v;
    int cnt;
    Solution(ListNode* head) {
        v.clear();
        cnt=0;
        while(head!=NULL){
            cnt++;
            v.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int res=rand()%cnt;
        return v[res];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */