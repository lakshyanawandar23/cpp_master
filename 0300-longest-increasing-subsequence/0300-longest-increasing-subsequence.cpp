class Solution {
public:
    int solve(vector<int>&num,vector<vector<int>>&dp,int n,int i,int prev){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int no=0+solve(num,dp,n,i+1,prev);
        int pick=0;
        if(prev==-1||num[i]>num[prev]){
            pick=1+solve(num,dp,n,i+1,i);
        }
        return dp[i][prev+1]=max(no,pick);
    }
    int lengthOfLIS(vector<int>& num) {
         int n=num.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(num,dp,n,0,-1);
    }
};