class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int>ans;
        vector<int>dis(n,1e9);
    vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        } //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        for(auto it:queries){
         queue<pair<int,int>>q;
            q.push({0,0});
            dis[0]=0;
            adj[it[0]].push_back(it[1]);
            bool flag=false;
             while(!q.empty()){
                 int k=q.size();
                 while(k--){
               auto p=q.front();
                 q.pop();
                 if(p.second==n-1) {
                 //    ans.push_back(dis[n-1]);
                  //   q.clear();
                   //  flag=true;
                    break;
                 }
            for(auto it:adj[p.second]){
                if(dis[it]>=p.first+1){
              q.push({p.first+1,it});
                    dis[it]=p.first+1;
                }
            }
                 }
        }
            ans.push_back(dis[n-1]);
        }
        return ans;
    }
};