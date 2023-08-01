//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<int>&ans,vector<int>adj[],int n,int src,vector<int>&vis){
        vis[src]=1;
        ans.push_back(src);
        for(auto it:adj[src]){
            if(vis[it]==0){
                solve(ans,adj,n,it,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>vis(v,0);
        solve(ans,adj,v,0,vis);
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends