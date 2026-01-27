class Solution {
public:
    int minCost(int n, vector<vector<int>>& e) {
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
            adj[e[i][1]].push_back({e[i][0],2*e[i][2]});
        }
        while(!q.empty()){
            auto p=q.top();
            q.pop();
        
            if(p.second==n-1) return dis[n-1];
            for(auto it:adj[p.second]){
                int d=p.first+it.second;
                if(dis[it.first]>d){
                    q.push({d,it.first});
                    dis[it.first]=d;
                }
            }
        }
        return -1;
    }
};