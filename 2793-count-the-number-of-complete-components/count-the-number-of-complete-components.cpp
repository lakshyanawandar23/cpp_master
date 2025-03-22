class Solution {
public:
void solve(vector<vector<int>>&adj,vector<int>&vis,int &v,int &edg,int src,int par){
    vis[src]=1;
    v++;
    for(auto it:adj[src]){
        edg++;
        if(vis[it]==0){
            solve(adj,vis,v,edg,it,src);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>>adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
              int v=0,edg=0;
              solve(adj,vis,v,edg,i,-1);
            //  cout<<v<<" "<<edg<<endl;
          int res=(v*(v-1));
          if(res==edg) cnt++;
            }
        }
        return cnt;
    }
};