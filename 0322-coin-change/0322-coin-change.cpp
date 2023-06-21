class Solution {
public:
    int solve(vector<int>&c,vector<vector<int>>&dp,int t,int &n,int i){
        if(i==0){
            if(t%c[0]==0){
                return t/c[0];
            }
            return 1000000000;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int pick=1000000000;
        int no=0+solve(c,dp,t,n,i-1);
        if(t>=c[i]){
            pick=1+solve(c,dp,t-c[i],n,i);
        }
        return dp[i][t]=min(pick,no);
    }
    int coinChange(vector<int>& c, int t) {
        int n=c.size();
       // sort(c.begin(),c.end());
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        int ans= solve(c,dp,t,n,n-1);
        if(ans>=INT_MAX||ans==1000000000) return -1;
        return ans;
    }
};