class Solution {
public:
    int mod=1000000007;
   int dp[101][101][101];
    int solve(int i,int n,int t,vector<int>&g,vector<int>&p,int &m){
        if(i==m){
            if(t<=0) return 1;
            return 0;
        }
        if(dp[i][t][n]!=-1){
            return dp[i][t][n];
        }
       int no=solve(i+1,n,t,g,p,m);
        int pick=0;
        if(g[i]<=n){
            pick=solve(i+1,n-g[i],max(t-p[i],0),g,p,m);
        }
        return dp[i][t][n]=(pick+no)%mod;
    }
    int profitableSchemes(int n, int t, vector<int>& g, vector<int>& p) {
        int  m=g.size();
         memset(dp, -1, sizeof(dp));
        return solve(0,n,t,g,p,m);
    }
};