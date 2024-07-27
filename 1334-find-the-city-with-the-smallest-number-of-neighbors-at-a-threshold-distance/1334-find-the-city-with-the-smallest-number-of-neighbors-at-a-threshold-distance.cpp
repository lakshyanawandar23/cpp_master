class Solution {
public:
    void solve(int i,int src,vector<int>&dis,vector<pair<int,int>>adj[],set<int>&mp,int &t){
        for(auto it:adj[src]){
            if(dis[it.first]>dis[src]+it.second&&dis[src]+it.second<=t){
             //   cout<<it.first<<endl;
              dis[it.first]=dis[src]+it.second;
              mp.insert(it.first);
                solve(i,it.first,dis,adj,mp,t);
            }
        }
        return ;
    }
    int findTheCity(int n, vector<vector<int>>& e, int t) {
   //     unordered_map<int,int>mp;
        vector<pair<int,int>>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
            adj[e[i][1]].push_back({e[i][0],e[i][2]});
        }
        int ans=1e9,res=-1;
        for(int i=0;i<n;i++){
            vector<int>dis(n,1e9);
            set<int>mp;
            dis[i]=0;
            solve(i,i,dis,adj,mp,t);
         //   cout<<mp.size()<<endl;
            if(ans>mp.size()){
             res=i;
                ans=mp.size();
            }
            else if(ans==mp.size()) res=max(res,i);
        }
        return res;
    }
};