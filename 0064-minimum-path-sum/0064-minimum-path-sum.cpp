class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&g,vector<vector<int>>&dp){
        if(i<0||j<0||i==n||j==m){
            return 1e9;
        }
        if(i==n-1&&j==m-1){
            return g[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=solve(i+1,j,n,m,g,dp);
        int r=solve(i,j+1,n,m,g,dp);
        return dp[i][j]= g[i][j]+min(d,r);
    }
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,g,dp);
    }
};