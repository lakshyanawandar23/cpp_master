class Solution {
public:
    int n;
    int solve(int i,int sum,vector<int>&dp,vector<int>&arr,int &k){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MIN;
        int maxi=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(maxi,arr[j]);
            ans=max(ans,solve(j+1,sum,dp,arr,k)+(maxi*(j-i+1)));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       n=arr.size();
        vector<int>dp(arr.size()+1,-1);
        return solve(0,0,dp,arr,k);
    }
};