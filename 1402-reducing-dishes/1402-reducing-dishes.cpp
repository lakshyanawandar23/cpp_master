class Solution {
public:
    int solve(int i,int cnt,vector<int>&s,vector<vector<int>>&dp){
        if(i==s.size()) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        int take=0,no=0;
        no=0+solve(i+1,cnt,s,dp);
        take=((cnt+1)*(s[i]))+solve(i+1,cnt+1,s,dp);
       // cout<<take<<" "<<cnt<<endl;
        return dp[i][cnt]=max(no,take);
    }
    int maxSatisfaction(vector<int>& s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        sort(s.begin(),s.end());
        return solve(0,0,s,dp);
    }
};