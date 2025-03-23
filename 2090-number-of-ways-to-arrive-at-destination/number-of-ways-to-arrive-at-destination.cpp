class Solution {
public:
    int countPaths(int n, vector<vector<int>>& r) {
        int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long ,int>>>q;
        q.push({0,0});
        vector<long long >dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            for(auto it:adj[p.second]){
              if(dis[it.first]>p.first+it.second){
                dis[it.first]=p.first+it.second;
                ways[it.first]=ways[p.second];
                q.push({dis[it.first],it.first});
              }
              else if(dis[it.first]==p.first+it.second){
                ways[it.first]=(ways[it.first]+ways[p.second])%mod;
              }
            }
        }
        return ways[n-1]%mod;
    }
};