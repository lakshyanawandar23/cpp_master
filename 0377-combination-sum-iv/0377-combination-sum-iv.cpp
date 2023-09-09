class Solution {
public:
    int solve(vector<int>&num,int t,int i,vector<vector<int>>&dp){
            if(t==0)  return 1;
        if(dp[i][t]!=-1) return dp[i][t];
        int pick=0;
        for(int i=0;i<num.size();i++){
        if(t>=num[i]){
            pick+=solve(num,t-num[i],i,dp);
        }
        }
        // no=solve(num,t,i+1,dp);
        return dp[i][t]=pick;
    }
    int combinationSum4(vector<int>& num, int t) {
        vector<vector<int>>dp(num.size(),vector<int>(t+1,-1));
        return solve(num,t,0,dp);
    }
};