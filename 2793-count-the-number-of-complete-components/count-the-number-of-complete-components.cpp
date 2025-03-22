class Solution {
public:
    void solve(vector<vector<int>>& adj, vector<int>& vis, int& v, int& edg, int src) {
        vis[src] = 1;
        v++;
        for (auto it : adj[src]) {
            edg++;
            if (vis[it] == 0) {
                solve(adj, vis, v, edg, it);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n);
        
        // Build adjacency list
        for (int i = 0; i < e.size(); i++) {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }

        int cnt = 0;
        vector<int> vis(n, 0);

        // Check each node to explore all components
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int v = 0, edg = 0;
                solve(adj, vis, v, edg, i);

                // Single node case - always a complete component
                if (v == 1) {
                    cnt++;
                    continue;
                }

                // Check if component is complete
                int res = (v * (v - 1));
                cout<<edg<<endl;
                if (res == edg) cnt++;
            }
        }
        return cnt;
    }
};
