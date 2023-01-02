class Solution {
public:
    int solve(int n,vector<int>&dp,int cnt){
        if(n==0){
            if(cnt==1){
                return 0;
            }
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            ans=max(ans,j*solve(n-j,dp,cnt+1));
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp,0);
    }
};