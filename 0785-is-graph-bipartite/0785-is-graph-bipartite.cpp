class Solution {
public:
    bool solve(int src,vector<int>adj[],vector<int>&c,int color){
        c[src]=color;
        for(auto it:adj[src]){
            if(c[it]==-1){
               if(!solve(it,adj,c,color^1)){
                   return false;
               }
            }
            if(c[it]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
          vector<int>adj[n];
        vector<int>c(n,-1);
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                adj[i].push_back(g[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(c[i]==-1){
             if(!solve(i,adj,c,0)) return false;
            }
        }
            return true;
    }
};