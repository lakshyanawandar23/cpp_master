class Solution {
public:
int solve2(int i,int j,vector<vector<int>>&dp2,int n,vector<vector<int>>&f){
    if(i<0||j<0||i>=n||j>=n) return 0;
     if(i==n-1&&j==n-1) return 0;
    if(i<=j) return 0;
 
    if(dp2[i][j]!=-1) return dp2[i][j];
    int s1=solve2(i,j+1,dp2,n,f);
    int s2=solve2(i-1,j+1,dp2,n,f);
    int s3=solve2(i+1,j+1,dp2,n,f);
    return dp2[i][j]=f[i][j]+max({s1,s2,s3}); 
}
int solve(int i,int j,vector<vector<int>>&dp,int n,vector<vector<int>>&f){
    if(i<0||j<0||i>=n||j>=n) return 0;
       if(i==n-1&&j==n-1) return 0;
    if(i>=j) return 0;
  //  if(i==n-1&&j==n-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int s1=solve(i+1,j,dp,n,f);
    int s2=solve(i+1,j-1,dp,n,f);
    int s3=solve(i+1,j+1,dp,n,f);
    return dp[i][j]=f[i][j]+max({s1,s2,s3}); 
}
    int maxCollectedFruits(vector<vector<int>>& f) {
        int  n=f.size(),sum1=0,i=0,j=0;
    while(i<n&&j<n){
        sum1+=f[i][j];
        f[i][j]=0;
        i=i+1;
        j=j+1;
    }
    vector<vector<int>>dp1(n,vector<int>(n,-1));
    vector<vector<int>>dp2(n,vector<int>(n,-1));
       sum1+=solve(0,n-1,dp1,n,f);
       //cout<<sum1<<endl;
       sum1+=solve2(n-1,0,dp2,n,f);
       return sum1;
    }
};