class Solution {
public:
    long long int solve(int i,int j,vector<vector<long long int >>&dp,vector<int>&a,vector<int>&b){
        if(i==a.size()) return 0;
        if(j==b.size()) return INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        long long int no=0+solve(i,j+1,dp,a,b);
        long long int take=((long long int)((long long int )(a[i])*(long long int)(b[j]))+solve(i+1,j+1,dp,a,b));
        return dp[i][j]=max(no,take);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long int>>dp(a.size(),vector<long long int>(b.size(),-1));
        return solve(0,0,dp,a,b);
    }
};