class Solution {
public:
    int solve(vector<int>&p,vector<vector<int>>&dp,int &f,int buy,int i){
             if(i==p.size()){
                 return 0;
             }
            if(dp[i][buy]!=-1){
                return dp[i][buy];
            }
        int profit=0;
         if(!buy){
             profit+=max(-p[i]+solve(p,dp,f,1,i+1),0+solve(p,dp,f,0,i+1));
         }
        else{
            profit+=max(p[i]-f+solve(p,dp,f,0,i+1),0+solve(p,dp,f,1,i+1));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& p, int f) {
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(p,dp,f,0,0);
    }
};