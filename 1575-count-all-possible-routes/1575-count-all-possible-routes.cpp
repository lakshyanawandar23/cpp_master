class Solution {
public:
    int solve(vector<int>&num,int s,int &f,int k,int &n,vector<vector<int>>&dp){
        int ans=0;
        if(s==f){
            ans++;
        }
        if(dp[s][k]!=-1){
            return dp[s][k];
        }
        for(int i=0;i<n;i++){
         if(i!=s){
              int res=abs(num[i]-num[s]);
             if((k-res)>=0){
                 ans=ans+solve(num,i,f,k-res,n,dp);
                 ans=ans%1000000007;
             }
         }
        } 
        return  dp[s][k]=ans;
    }
    int countRoutes(vector<int>& num, int s, int f, int k) {
        int  n=num.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
      return solve(num,s,f,k,n,dp);
    }
};