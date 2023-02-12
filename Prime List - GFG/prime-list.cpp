//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    int  arr[11002]={0};
    void solve(){
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=11001;i++){
        if(arr[i]==0){
        for(int j=i*i;j<=11001;j+=i){
             arr[j]=1;   
        }
        }
    }
    }
    Node *primeList(Node *head){
        solve();
        Node* curr=new Node(-1);
        Node* head2=curr;
        while(head!=NULL){
            int ans=head->val;
            int l=ans,r=ans,res;
            if(l==1){
                l++;
            }
            while(arr[l]!=0&&l>1){
                l--;
            }
            while(r<11002&&arr[r]!=0){
                r++;
            }
            if(abs(l-ans)<=r-ans){
                res=l;
            }
            else{
                res=r;
            }
            Node* temp=new Node(res);
           // cout<<temp->val<<endl;
            curr->next=temp;
            curr=temp;
            head=head->next;
        }
        return head2->next;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends