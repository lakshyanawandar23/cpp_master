class Solution {
public:
    int dfs(int src,vector<int>adj[],vector<int>&t,int &n){
        int ans=0,res=0;
        for(auto val:adj[src]){
            ans=max(ans,t[src]+dfs(val,adj,t,n));
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& t) {
        vector<int>adj[n];//adjancy list
        for(int i=0;i<m.size();i++){
            if(m[i]!=-1){
                adj[m[i]].push_back(i);
            }
        }
        return dfs(headID,adj,t,n);
    }
};