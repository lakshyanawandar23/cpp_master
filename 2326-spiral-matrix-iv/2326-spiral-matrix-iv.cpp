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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m,vector<int>(n,-1));
      int u=0,l=0,r=n-1,d=m-1,t=0;
   while(head!=NULL&&t<=m*n){
       for(int i=l;i<=r&&head!=NULL&&t<=m*n;++i){
         v[u][i]=head->val;
          // cout<<v[u][i]<<endl;
           head=head->next;
           t++;
      
       
       }
      ++u;
     for(int i=u;i<=d&&head!=NULL&&t<=m*n;++i){
      v[i][r]=head->val;
       //  cout<<v[i][r]<<endl;
         head=head->next;
       
         t++;
     }
     r--;
       if(head==NULL){
           break;}
        for(int i=r;i>=l&&head!=NULL&&t<=m*n;i--){
      v[d][i]=head->val;
          //  cout<<v[d][i]<<endl;
         head=head->next;
            t++;
      
         
        }
     --d;
     
     
        for(int i=d;i>=u&&head!=NULL&&t<=m*n;i--){
      v[i][l]=head->val;
            //cout<<v[i][l]<<endl;
         head=head->next;
     t++;
          
        }
     ++l;
       }
        return v;
    
    }
};