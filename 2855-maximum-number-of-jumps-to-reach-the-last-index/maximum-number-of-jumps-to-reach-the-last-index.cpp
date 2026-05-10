class Solution {
public:
  int solve(int i,vector<int>&dp,vector<int>&num,int t){
    if(i>=num.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int take=INT_MIN,no=INT_MIN;
   // no=solve(i+1,dp,num,t);
    for(int j=i+1;j<num.size();j++){
    if(abs(num[j]-num[i])<=t){
        take=max(take,1+solve(j,dp,num,t));
    }
    }
    return dp[i]=max(no,take);
  }
    int maximumJumps(vector<int>& num, int t) {
        int n=num.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,dp,num,t);
        return  ans<0?-1:ans;
    }
};