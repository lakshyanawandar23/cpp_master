class Solution {
public:
    int findNumberOfLIS(vector<int>& num) {
        int n=num.size(),cnt=0,res=1;
        vector<int>dp(n+1,1);
        vector<int>ans(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(num[i]>num[j]&&dp[j]+1>dp[i]){
                    dp[i]=max(dp[i],1+dp[j]);//finding max length of lis
                    ans[i]=ans[j];//find count no of max length lis
                }
                else if(num[i]>num[j]&&dp[i]==dp[j]+1){
                    ans[i]+=ans[j];
                }
            }
            res=max(res,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(res==dp[i]){
             cnt+=ans[i];
            }
        }
        return cnt;
    }
};