class Solution {
public:
    int solve(vector<int>&dp,int n){
        if(n==0) {
            return 0;
        }
        if(dp[n]!=-1){
        return dp[n];
        }
        int ans=1e9;
        for(int j=1;j<=sqrt(n);j++){
            if((n-j*j)>=0){
                ans=min(ans,1+solve(dp,n-(j*j)));
            }
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(dp,n);
    }
};