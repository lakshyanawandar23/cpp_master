class Solution {
public:
    int dp[21][21];
     int solve(vector<int>num,int i,int j,int chance,int dp[21][21]){
    if(i>j){
        return 0;
    }
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
         int val=0;
        if(!chance){
        val=max(num[i]+solve(num,i+1,j,1,dp),num[j]+solve(num,i,j-1,1,dp));
        }
        else{
             val=min(solve(num,i+1,j,0,dp),solve(num,i,j-1,0,dp));
        }
         return dp[i][j]=val;
    }
    bool PredictTheWinner(vector<int>& num) {
        int n=num.size();
      //  vector<vector<long long int>>dp[n+1];
        memset(dp,-1,sizeof(dp));
         int sum=0;
        for(int i=0;i<n;i++){
            sum+=num[i];
        }
         int ans=solve(num,0,n-1,0,dp);
      //  cout<<ans<<endl;
        return ans>=(sum-ans);
    }
};