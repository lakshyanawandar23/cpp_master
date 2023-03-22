class Solution {
public:
int ans=INT_MAX;
void solve(int s,vector<int>&vis,vector<pair<int,int>>adj[]){
    vis[s]=1;
    for(auto val:adj[s]){
        ans=min(ans,val.second);
        if(vis[val.first]==0){
            solve(val.first,vis,adj);
        }
    }
}
    int minScore(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>adj[n+1];
        vector<int>vis(n+1,0);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]-1].push_back({r[i][1]-1,r[i][2]});
             adj[r[i][1]-1].push_back({r[i][0]-1,r[i][2]});
        }
        solve(0,vis,adj);
        return ans;
    }
};