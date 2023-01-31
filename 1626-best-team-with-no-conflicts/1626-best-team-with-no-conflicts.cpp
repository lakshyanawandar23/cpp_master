class Solution {
public:
   static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
           return a.second>b.second;
        }
        return a.first<b.first;
    }
    int solve(int i,vector<pair<int,int>>&v,vector<vector<int>>&dp,int prev){
        if(i==v.size()){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int no=0+solve(i+1,v,dp,prev);
        int select=0;
        if(prev<=v[i].second){
            select=v[i].first+solve(i+1,v,dp,v[i].second);
        }
        return dp[i][prev]=max(no,select);
    }
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        int n=s.size(),mx=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            mx=max(mx,a[i]);
            v.push_back({s[i],a[i]});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>dp(n,vector<int>(mx+1,-1));
        return solve(0,v,dp,0);
    }
};