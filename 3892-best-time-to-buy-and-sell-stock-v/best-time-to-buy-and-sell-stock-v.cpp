class Solution {
public:
 //long long  dp[3005][1503][3];
 long long int solve(int i,vector<int>&p,int k,int curr,vector<vector<vector<long long int>>>&dp){
    if(k==0){
        if(curr==0) return 0;
        return -1e9;
    }
    if(i>=p.size()){
        if(curr==0) return 0;
         return -1e9;
    }
    //if(curr==0||k==0) return 0;
    if(dp[i][k][curr]!=-1) return dp[i][k][curr];
    long long int p2=-1e9;
   long long int  p3=solve(i+1,p,k,curr,dp);
    if(curr==0){
      p2=max((p[i]+solve(i+1,p,k,1,dp)),(-p[i]+solve(i+1,p,k,2,dp)));
    }
    else if (curr==1){
        p2=(-p[i]+solve(i+1,p,k-1,0,dp));
    }
     else {
        p2=(p[i]+solve(i+1,p,k-1,0,dp));
    }
   // cout<<p2<<" "<<p3<<endl;
    return dp[i][k][curr]=max(p2,p3);
 }
    long long maximumProfit(vector<int>& p, int k) {
      //  memset(dp,-1,sizeof(dp));
        int n=p.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>((n/2) +1,vector<long long>(3,-1)));
    return  solve(0,p,k,0,dp);
    
    }
};