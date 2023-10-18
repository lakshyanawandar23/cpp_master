class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n+1];
        int indegree[n+1];
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }
        queue<int>q;
        vector<int> dist(n+1);
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                dist[i]=time[i-1];
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:adj[node]){
                dist[it]=max(dist[it],dist[node]+time[it-1]);
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }        
        }
        int ans=INT_MIN;
        for(int i=0;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        return ans;


    }
};