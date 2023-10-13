class Solution {
public:
    int solve(int n,int i,vector<int>&c,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=min(c[i]+solve(n,i+1,c,dp),c[i]+solve(n,i+2,c,dp));
    }
    int minCostClimbingStairs(vector<int>& c) {
        vector<int>dp(c.size()+2,-1);
        return min(solve(c.size(),0,c,dp),solve(c.size(),1,c,dp));
    }
};