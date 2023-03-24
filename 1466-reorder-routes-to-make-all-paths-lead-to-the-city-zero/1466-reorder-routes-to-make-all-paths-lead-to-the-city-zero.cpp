class Solution {
public:
    void dfs(int s,vector<int>&vis,vector<pair<int,int>>adj[],int &cnt){
        vis[s]=1;
        for(auto val:adj[s]){
            if(vis[val.first]==0){
                cnt+=val.second;
                dfs(val.first,vis,adj,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<int>vis(n,0);
        vector<pair<int,int>>adj[n];
        for(int i=0;i<c.size();i++){
            adj[c[i][0]].push_back({c[i][1],1});
          adj[c[i][1]].push_back({c[i][0],0});
        }
        int cnt=0;
        dfs(0,vis,adj,cnt);
        return cnt;
    }
};