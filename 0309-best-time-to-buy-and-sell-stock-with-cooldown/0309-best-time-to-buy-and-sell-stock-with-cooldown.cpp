class Solution {
public:
    int solve(vector<int>&p,int i,vector<vector<int>>&dp,int n,int buy){
         if(i>=n){
             return 0;
         }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int ans=0;
        if(!buy){
            ans+=max(-p[i]+solve(p,i+1,dp,n,1),0+solve(p,i+1,dp,n,0));
        }
        else{
            ans+=max(p[i]+solve(p,i+2,dp,n,0),0+solve(p,i+1,dp,n,1));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(p,0,dp,n,0);
    }
};