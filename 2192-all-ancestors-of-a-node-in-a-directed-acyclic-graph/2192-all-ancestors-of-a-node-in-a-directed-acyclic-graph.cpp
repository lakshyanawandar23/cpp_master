class Solution {
public:
    void dfs(vector<int>adj[],vector<vector<int>>&v,int src,int &node,vector<int>&vis){
        vis[src]=1;
        for(auto it:adj[src]){
            if(vis[it]==0){
            v[it].push_back(node);
            dfs(adj,v,it,node,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        vector<int>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
        }
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(adj,v,i,i,vis);
        }
        return v;
    }
};