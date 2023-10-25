//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int w,vector<vector<int>>&dp,int val[],int wt[],int &n){
        if(i==n){
            return 0;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int pick=0,no=0;
        if(w>=wt[i]){
            //cout<<val[i]<<endl;
            pick=val[i]+solve(i,w-wt[i],dp,val,wt,n);
        }
        no=solve(i+1,w,dp,val,wt,n);
        return dp[i][w]=max(no,pick);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return solve(0,w,dp,val,wt,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends