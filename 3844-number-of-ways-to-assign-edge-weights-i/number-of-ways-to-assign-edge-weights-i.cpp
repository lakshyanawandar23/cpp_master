class Solution {
public:
    int MOD = 1e9 + 7;
    int dfs(vector<vector<int>>& adj, int curr, int parent){
        int depth = 0;
        for(auto node : adj[curr]){
            if(node == parent) continue;
            depth = max(depth, dfs(adj, node, curr) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int depth = dfs(adj, 1, 0);
        
        long long ans = 1; 
        while(--depth){
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
};