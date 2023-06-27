class Solution {
public:
    int solve(vector<pair<int,int>>&v,int i,int prev,vector<vector<int>>&dp){
        if(i==v.size()){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int no=0+solve(v,i+1,prev,dp);
        int pick=0;
        if(v[i].second>=prev){
            pick=v[i].first+solve(v,i+1,v[i].second,dp);
        }
        return dp[i][prev]=max(no,pick);
    }
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<pair<int,int>>v;
        int mx=0;
        for(int i=0;i<s.size();i++){
            mx=max(mx,a[i]);
            v.push_back({s[i],a[i]});
        }
        sort(v.begin(),v.end());
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(mx+1,-1));
        return solve(v,0,0,dp);
    }
};