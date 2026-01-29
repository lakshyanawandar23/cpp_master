class Solution {
public:
 void solve(vector<pair<int,int>>adj[],int src,vector<long long int>&dis){
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>q;
    q.push({0,src});
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        for(auto  it:adj[p.second]){
          long long  int d=p.first+it.second;
            if(dis[it.first]>d){
                dis[it.first]=d;
                q.push({dis[it.first],it.first});
            }
        }
    }
 }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,int>>adj[26];
        vector<vector<long long int>>dis(26,vector<long long int>(26,INT_MAX));
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        for(int i=0;i<26;i++){
            solve(adj,i,dis[i]);
        }
        long long int ans=0;
        for(int i=0;i<source.size();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(u==v) continue;
            if(dis[u][v]==INT_MAX) return -1;
            ans+=dis[u][v];
        }
        return ans;
    }
};