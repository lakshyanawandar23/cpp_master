class Solution {
public:
    void dfs(int src,vector<int>&vis,vector<int>adj[]){
        vis[src]=1;
        for(auto val:adj[src]){
            if(vis[val]==0){
                dfs(val,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& g) {
        int n=g.size(),cnt=0;
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};