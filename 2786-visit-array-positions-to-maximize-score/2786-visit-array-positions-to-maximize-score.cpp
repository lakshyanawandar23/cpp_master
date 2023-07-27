class Solution {
public:
    long long int solve(vector<int>&num,vector<vector<long long int>>&dp,int i,int prev,int &x){
        if(i==num.size()){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        long long int  include=0,exc=0;
        exc=0+solve(num,dp,i+1,prev,x);
        if(prev==0&&num[i]%2==0||prev==1&&num[i]%2==1){
            include=num[i]+solve(num,dp,i+1,num[i]%2,x);
        }
        else {
            include=num[i]-x+solve(num,dp,i+1,num[i]%2,x);
        }
        return dp[i][prev]=max(include,exc);
    }
    long long maxScore(vector<int>& num, int x) {
        int n=num.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(2,-1));
        return solve(num,dp,1,num[0]%2,x)+num[0];
    }
};