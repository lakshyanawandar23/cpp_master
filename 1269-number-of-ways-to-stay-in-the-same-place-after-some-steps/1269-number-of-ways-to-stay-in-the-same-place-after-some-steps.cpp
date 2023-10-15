class Solution {
public:
    int m=1000000007;
    int dp[501][501];
    int solve(int s,int n,int idx){
        if(idx<0||idx>=n){
            return 0;
        }
        if(s==0){
            if(idx==0) return 1;
            return 0;
        }
        if(dp[idx][s]!=-1) return dp[idx][s];
      long long  int a=solve(s-1,n,idx)%m;
     long long   int b=solve(s-1,n,idx-1)%m;
     long long    int c=solve(s-1,n,idx+1)%m;
        return dp[idx][s]=(a+b+c)%m;
    }
    int numWays(int s, int n) {
       memset(dp,-1,sizeof(dp));
        return solve(s,n,0);
    }
};