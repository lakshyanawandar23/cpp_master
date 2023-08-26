class Solution {
public:
    int solve(vector<vector<int>>&s,int &n,vector<vector<int>>&dp,int p,int i){
        if(i==n){
            return 0;
        }
        if(dp[i][p+1]!=-1){
            return dp[i][p+1];
        }
        int pick=0,no=0;
        if(p==-1||s[p][1]<s[i][0]){
            pick=1+solve(s,n,dp,i,i+1);
        }
        no=0+solve(s,n,dp,p,i+1);
        return dp[i][p+1]=max(no,pick);
    }
    int findLongestChain(vector<vector<int>>& s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(s.begin(),s.end());
        return solve(s,n,dp,-1,0);
    }
};