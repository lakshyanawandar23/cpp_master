class Solution {
public:
   int dp[1001][1001];
    int solve(vector<int>&num,int &k,int i,int rem){
        if(dp[i][rem]!=-1) return dp[i][rem];
        int res=1;
        for(int j=i+1;j<num.size();j++){
            if((num[i]+num[j])%k==rem){
              res+=solve(num,k,j,rem);
              break;
            }
        }
        return dp[i][rem]=res;
    }
    int maximumLength(vector<int>& num, int k) {
        int n=num.size();
        memset(dp,-1,sizeof(dp));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               //  memset(dp,-1,sizeof(dp));
                res=max(res,1+solve(num,k,j,(num[i]+num[j])%k));
            }
        }
        return res;
    }
};