class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& v, int s, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back({e[i][1],v[i]});
            adj[e[i][1]].push_back({e[i][0],v[i]});
        }
        vector<double>vis(n,0.0);
        priority_queue<pair<double,int>>q;
        vis[s]=1;
        q.push({1.0,s});
       // double ans=0.0;
        while(!q.empty()){
         auto p=q.top();
            q.pop();
            if(p.second==end){
                return p.first;
            }
            for(auto it:adj[p.second]){
                if((it.second*p.first)>vis[it.first]){
                vis[it.first]=(it.second*p.first);
              q.push({vis[it.first],it.first});
                }
            }
        }
        return 0;
    }
};