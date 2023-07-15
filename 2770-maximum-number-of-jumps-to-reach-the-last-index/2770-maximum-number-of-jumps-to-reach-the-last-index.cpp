class Solution {
public:
    int solve(vector<int>&num,vector<int>&dp,int i,int prev,int &t,int &n){
        if(i==n-1){
            return 0;
          }
        if(dp[i]!=-1){
            return dp[i];
        }
        int pick=-10000;
        for(int j=i+1;j<n;j++){
            int diff=num[j]-num[i];
        if(abs(diff)<=t){
            pick=max(pick,1+solve(num,dp,j,i,t,n));
        }
        }
           return dp[i]=pick;
    }
    int maximumJumps(vector<int>& num, int t) {
        int n=num.size();
        vector<int>dp(n+5,-1);
        int ans= solve(num,dp,0,0,t,n);
        if(ans<0) return -1;
        return ans;
    }
};