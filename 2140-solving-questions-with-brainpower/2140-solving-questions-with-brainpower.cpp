class Solution {
public:
    long long int solve(int i,vector<vector<int>>&q,vector<long long int>&dp){
        if(i>=q.size()) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
       long long int pick=0;
        int skip=i+q[i][1]+1;
        pick=q[i][0]+solve(skip,q,dp);
        dp[i]=max(pick,solve(i+1,q,dp));
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long int>dp(n+1,-1);
        return solve(0,q,dp);
    }
};