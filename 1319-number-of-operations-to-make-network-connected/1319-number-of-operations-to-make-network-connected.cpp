class Solution {
public:
    void dfs(int s,vector<int>adj[],vector<int>&vis,int &ans){
        vis[s]=1;
        for(auto val:adj[s]){
            if(vis[val]==0){
                dfs(val,adj,vis,ans);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        if(n-1>c.size()){
            return -1;
        }
        for(int i=0;i<c.size();i++){
            adj[c[i][0]].push_back(c[i][1]);
           adj[c[i][1]].push_back(c[i][0]);
        }
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adj,vis,ans);
            }
        }
        return (cnt-1);
    }
};