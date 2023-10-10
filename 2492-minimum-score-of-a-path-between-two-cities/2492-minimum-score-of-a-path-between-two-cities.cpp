class Solution {
public:
    void solve(int src,int &ans,vector<pair<int,int>>adj[],vector<int>&vis){
        vis[src]=1;
        for(auto it:adj[src]){
            ans=min(ans,it.second);
          if(vis[it.first]==0){
              solve(it.first,ans,adj,vis);
          }
        }
        return ;
    }
    int minScore(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
              adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        int ans=INT_MAX;
        vector<int>vis(n+1,0);
        solve(1,ans,adj,vis);
        return ans;
    }
};