class Solution {
public:
    int m=1000000007;
  long long  int solve( int  pick,int delivery,vector<vector<long long int>>&dp,int n){
        if(pick==0&&delivery==0){
            return 1;
        }
        if(dp[pick][delivery]!=-1){
            return dp[pick][delivery];
        }
      long long int cnt=0,res=0;
        if(pick>0){
          cnt=((pick)%m*(solve(pick-1,delivery,dp,n)%m))%m;
        }
        if(delivery>pick){
          res=((delivery-pick)%m*(solve(pick,delivery-1,dp,n)%m))%m;
        }
        return dp[pick][delivery]=cnt+res;
    }
    int countOrders(int n) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(n+1,-1));
        return solve(n,n,dp,n);
    }
};