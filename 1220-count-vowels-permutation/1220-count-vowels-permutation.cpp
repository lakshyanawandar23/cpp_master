class Solution {
public:
    map<int,vector<int>>m;
    int mod=1000000007;
    int solve(int n, vector<vector<int>>&dp,int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }
        int a=0,b=0;
      if(prev==0){
          for(int i=1;i<=5;i++){
              a=(a+solve(n-1,dp,i))%mod;
          }
      }
        else{
            for(auto it:m[prev]){
                b=(b+solve(n-1,dp,it))%mod;
            }
        }
        return dp[n][prev]=(a+b)%mod;
        
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
         m[1].push_back(2);
     m[2].push_back(1);
     m[2].push_back(3);
     m[3].push_back(1);
     m[3].push_back(2);
     m[3].push_back(4);
     m[3].push_back(5);
     m[4].push_back(3);
     m[4].push_back(5);
     m[5].push_back(1);
        return solve(n,dp,0);
    }
};