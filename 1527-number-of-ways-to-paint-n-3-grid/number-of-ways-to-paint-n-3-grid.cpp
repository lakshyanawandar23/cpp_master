class Solution {
public:
  int dp[5001][5][5][5];
  int mod=1e9+7;
  int solve(int idx,int p1,int p2,int p3,int &n){
    if(idx==n) return 1;
    if(dp[idx][p1+1][p2+1][p3+1]!=-1) return dp[idx][p1+1][p2+1][p3+1];
    int ans=0;
    for(int i=1;i<=3;i++){
        if(i==p1) continue;
        for(int j=1;j<=3;j++){
            if(j==p2 || j==i) continue;

            for(int k=1;k<=3;k++){
                if(k==p3||k==j) continue;
                ans=((ans%mod)+solve(idx+1,i,j,k,n)%mod)%mod;
            }
        }
    }
     return dp[idx][p1+1][p2+1][p3+1]=ans;
  }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return  solve(0,-1,-1,-1,n);
    }
};