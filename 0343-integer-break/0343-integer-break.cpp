class Solution {
public:
    int solve(int &n,int ans,vector<int>&dp){
        if(ans==0){
            return 1;
        }
        if(dp[ans]!=-1){
            return dp[ans];
        }
        int res=-1;
        for(int i=1;i<n;i++){
            if(i<=ans){
            res=max(res,i*solve(n,ans-i,dp));
        }
        }
        return dp[ans]=res;
    }
    int integerBreak(int n) {
        vector<int>dp(10000,-1);
        return solve(n,n,dp);
    }
};