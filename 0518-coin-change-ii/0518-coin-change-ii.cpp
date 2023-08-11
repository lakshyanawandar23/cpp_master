class Solution {
public:
    int solve(int i,int t,vector<int>&c,vector<vector<int>>&dp,int &n){
        if(i==n-1){
            if(t%c[i]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int no=solve(i+1,t,c,dp,n);
        int pick=0;
        if(t>=c[i]){
            pick+=solve(i,t-c[i],c,dp,n);
        }
      return   dp[i][t]=no+pick;
    }
    int change(int t, vector<int>& c) {
        vector<vector<int>>dp(c.size(),vector<int>(t+1,-1));
        sort(c.begin(),c.end());
        int n=c.size();
        return solve(0,t,c,dp,n);
    }
};