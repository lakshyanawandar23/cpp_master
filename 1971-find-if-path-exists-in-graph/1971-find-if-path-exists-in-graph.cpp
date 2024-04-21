class Solution {
public:
    bool solve(vector<int>&vis,vector<int>adj[],int s,int d){
        if(s==d) return true;
        vis[s]=1;
        for(auto it:adj[s]){
            if(vis[it]==0){
                if(solve(vis,adj,it,d)) {
                    return true;
            }
        }
                   }
               //    vis[s]=0;
                   return false;
    }
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        vector<int>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        vector<int>vis(n,0);
        return solve(vis,adj,s,d);
    }
};