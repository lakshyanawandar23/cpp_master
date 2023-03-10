class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<int>&vis,int cnt,int &ans,int p){
        vis[src]=1;
        cnt++;
        for(auto val:adj[src]){
            if(vis[val]==0){
                dfs(val,adj,vis,cnt,ans,p);
            }
          else  if(vis[val]==1){
              if(val==p){
                ans=max(ans,cnt-1);
            }
          }
        }
    }
    int longestCycle(vector<int>& e) {
        int n=e.size();
        vector<int>adj[n];
        for(int i=0;i<e.size();i++){
            if(e[i]>=0){
            adj[e[i]].push_back(i);
        }
        }
        vector<int>vis(n,0);
        int ans=-1;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,cnt,ans,i);
            }
        }
        return ans;
    }
};