class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& e, vector<int>& d) {
        vector<int>dis(n,2e9);
        vector<int>vis(n,0);
        //simple dijkstra probelm it is 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<pair<int,int>>adj[n];
        int cnt=n;
        for(auto it:e){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // q<pair<time,node>>
        q.push({0,0});
        dis[0]=0;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(vis[p.second]) continue;
            vis[p.second]=1;
            for(auto it:adj[p.second]){
                 int node=it.first;
                int t=it.second;
                if(t+p.first<d[it.first]&&dis[it.first]>t+p.first){
                    dis[it.first]=t+p.first;
                    q.push({dis[it.first],it.first});
                }
            }
        }
          for(int i=0;i<n;i++){
              if(dis[i]==2e9){
                  dis[i]=-1;
              }
          }
              return dis;
    }
                        
};