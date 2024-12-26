class Solution {
public:
    int dp[22][3000];
    int solve(int i,int t,vector<int>&num){
        if(i==num.size()){
            if(t==0) return 1;
            return 0;
        }
        if(dp[i][t+1000]!=-1) return dp[i][t+1000];
        int pos=solve(i+1,t-num[i],num);
        int neg=solve(i+1,t+num[i],num);
        return dp[i][t+1000]=pos+neg;
    }
    int findTargetSumWays(vector<int>& num, int t) {
        int n=num.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,t,num);
    }
};