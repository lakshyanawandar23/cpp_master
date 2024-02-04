class Solution {
public:
    int solve(vector<int>&dp,int &n,vector<int>&arr,int i,int &k){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0,maxi=0;
        for(int j=i;j<=min(n-1,i+k-1);j++){
            ans=max(ans,arr[j]);
        maxi=max(maxi,solve(dp,n,arr,j+1,k)+ans*(j-i+1));
            
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
       return solve(dp,n,arr,0,k);
    }
};