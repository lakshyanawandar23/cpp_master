class Solution {
public:
    int dp[4001][1010];
    int m=1000000007;
    int solve(int s,int &e,int k){
        if(k==0){
            if(s==e)  return 1;
            return 0;
        }
        if(dp[s+2000][k]!=-1)  return dp[s+2000][k];
       long long int a=solve(s-1,e,k-1)%m;
       long long int b=solve(s+1,e,k-1)%m;
        return dp[s+2000][k]=(a+b)%m;
    }
    int numberOfWays(int s, int e, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,e,k);
    }
};