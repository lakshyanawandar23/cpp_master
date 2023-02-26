//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int src,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
      vis[src]=1;
      ans.push_back(src);
      for(auto val:adj[src]){
          if(vis[val]==0){
              dfs(val,adj,vis,ans);
          }
      }
  }
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        // code here
        int cnt=0;
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++){
            if(vis[i]==0){
            vector<int>ans;
            bool flag=true;
              dfs(i,adj,vis,ans);
            for(int j=0;j<ans.size();j++){
                if(adj[ans[j]].size()<ans.size()-1){
                   // cout<<adj[i].size()<<endl;
                    //cout<<ans.size()<<endl;
                    //cout<<i<<endl;
                    flag=false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends