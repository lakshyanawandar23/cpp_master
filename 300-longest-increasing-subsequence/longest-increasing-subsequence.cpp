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
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      // return solve(num,dp,n,0,-1);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
             int no=0+dp[i+1][prev+1];
           int pick=0;
        if(prev==-1||num[i]>num[prev]){
            pick=1+dp[i+1][i+1];
        }
         dp[i][prev+1]=max(no,pick);
            }
        }
        return dp[0][0];
    }
};