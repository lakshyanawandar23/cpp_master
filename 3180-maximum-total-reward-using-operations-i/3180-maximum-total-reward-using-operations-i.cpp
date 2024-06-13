class Solution {
public:
    int solve(int i,int &n,vector<vector<int>>&dp,vector<int>&v,int cnt){
        if(i==n) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        int no=0,pick=0;
        no=0+solve(i+1,n,dp,v,cnt);
        if(cnt<v[i]){
            pick=v[i]+solve(i+1,n,dp,v,cnt+v[i]);
        }
        return dp[i][cnt]=max(no,pick);
    }
    int maxTotalReward(vector<int>& v) {
        //states  (idx) pick non-pick format
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(4001,-1));
        return solve(0,n,dp,v,0);
    }
};