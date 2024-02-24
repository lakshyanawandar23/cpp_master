class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<pair<int,int>>adj[n];
        for(auto it:m){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]}); 
         //   q.push({it[2],{it[0],it[1]}});
        }
        adj[0].push_back({f,0});
        adj[f].push_back({0,0});
        vector<int>vis(n,0);
        vis[0]=1;
       // vis[f]=1;
        q.push({0,0});
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            vis[p.second]=1;
            for(auto it:adj[p.second]){
         if((vis[it.first]==0)&&it.second>=p.first){
              // vis[p.second.second]=1;
               //vis[p.second.first]=1;
               //t=p.first;
             q.push({it.second,it.first});
           } 
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};