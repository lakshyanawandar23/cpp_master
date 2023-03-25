class Solution {
public:
    void dfs(int s,vector<int>&vis,vector<int>adj[],long long int &res){
        vis[s]=1;
        res++;
        for(auto val:adj[s]){
            if(!vis[val]){
                dfs(val,vis,adj,res);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& e) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        long long ans=0,tot=0,cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                long long int res=0;
            dfs(i,vis,adj,res);
                if(cnt>1){
                    ans+=(tot*res);
                }
                tot+=res;
            }
        }
        return ans;
    }
};