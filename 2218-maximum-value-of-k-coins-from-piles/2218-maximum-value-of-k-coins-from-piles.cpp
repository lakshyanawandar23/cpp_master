class Solution {
public:
    int solve(int i,vector<vector<int>>&p,vector<vector<int>>&dp,int k,int n){
        if(i==n||k==0){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int pick=INT_MIN,sum=0;
        for(int j=0,temp=k;j<p[i].size()&&temp>0;j++){
            temp--;
            sum+=p[i][j];
            pick=max(pick,sum+solve(i+1,p,dp,temp,n));
        }
        pick=max(pick,solve(i+1,p,dp,k,n));
        return dp[i][k]=pick;
    }
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,p,dp,k,n);
    }
};