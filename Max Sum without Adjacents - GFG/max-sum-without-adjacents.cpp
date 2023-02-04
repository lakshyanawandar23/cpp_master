//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
   int solve(int i,vector<int>&dp,int *arr,int n){
       if(i>=n){
           return 0;
       }
       if(dp[i]!=-1){
           return dp[i];
       }
       int no=0+solve(i+1,dp,arr,n);
       int pick=arr[i]+solve(i+2,dp,arr,n);
       return dp[i]=max(pick,no);
   }
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	   return solve(0,dp,arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends