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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      TreeNode* solve(vector<int>&nums,int s,int e){
      if(s>e){
          return NULL;}
      int m=(s+e)/2;
    TreeNode* root=new TreeNode(nums[m]);
    root->left=solve(nums,s,m-1);
    root->right=solve(nums,m+1,e);
      return root;
      }
    TreeNode* sortedListToBST(ListNode* head) {
          vector<int>nums;
      while(head){
          nums.push_back(head->val);
          head=head->next;}
     return solve(nums,0,nums.size()-1);
    }
};