class Solution {
public:
    int ans,sum;
   long long int dfs(vector<vector<int>>&adj,vector<int>&vis,int src,vector<int>&value,int &k){
        vis[src]=1;
       long long int s=value[src];
     //   cout<<sum<<endl;
        for(auto it:adj[src]){
            if(vis[it]==0){
                s+=dfs(adj,vis,it,value,k);
            }
        }
        if(s%k==0) ans++;
        return s;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& values, int k) {
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n+1);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        ans=0;
        sum=0;
        dfs(adj,vis,0,values,k);
   return ans;
    }
};