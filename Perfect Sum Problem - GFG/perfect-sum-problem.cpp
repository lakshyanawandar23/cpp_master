//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int m=1000000007;
	int solve(int arr[],int sum,vector<vector<int>>&dp,int n,int i ){
	    if(i==n){
	        return sum==0;
	    }
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    int no=solve(arr,sum,dp,n,i+1);
	    int pick=0;
	    if(sum>=arr[i]){
	        pick=solve(arr,sum-arr[i],dp,n,i+1);
	    }
	    return dp[i][sum]=(pick+no)%m;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum,dp,n,0);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends