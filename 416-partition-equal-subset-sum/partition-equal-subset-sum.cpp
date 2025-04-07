class Solution {
public:
  int dp[201][100001];
  bool solve(int i,vector<int>&num,int &sum,int ans){
    if(i==num.size()){
        if((sum-ans)==ans) return true;
        return false;
    }
     if(dp[i][ans]!=-1) return dp[i][ans];
        if(solve(i+1,num,sum,ans+num[i])){
            return dp[i][ans]= true;
        }
    return dp[i][ans] =solve(i+1,num,sum,ans);

  }
    bool canPartition(vector<int>& num) {
        int sum=0;
        for(auto it:num){
            sum+=it;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,num,sum,0);
    }
};