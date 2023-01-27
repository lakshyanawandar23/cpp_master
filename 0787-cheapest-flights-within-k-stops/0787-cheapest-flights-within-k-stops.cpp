class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<f.size();i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        vector<int>dis(n,INT_MAX);
        int s=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty()&&s<=k){
            int size=q.size();
            while(size--){
            auto p=q.front();
            q.pop();
            for(auto it:adj[p.first]){
                int node=it.first;
                int cost=it.second;
                if(p.second+cost<dis[node]){
                    dis[node]=p.second+cost;
                    q.push({node,dis[node]});
                }
            }
        }
            s++;
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};