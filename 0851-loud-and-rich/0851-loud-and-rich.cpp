class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&q,int src,int &res,vector<int>&vis){
       vis[src]=1;
        if(q[src]<q[res]){
            res=src;
        }
        for(auto val:adj[src]){
            if(vis[val]==0){
            dfs(adj,q,val,res,vis);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& e, vector<int>& q) {
        vector<int>ans;
        int n=q.size();
        vector<int>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][1]].push_back(e[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            int res=i;
            dfs(adj,q,i,res,vis);
            ans.push_back(res);
        }
        return ans;
    }
};