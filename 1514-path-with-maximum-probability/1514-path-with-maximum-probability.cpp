class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int st, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back({e[i][1],p[i]});
            adj[e[i][1]].push_back({e[i][0],p[i]});
        }
        priority_queue<pair<double,int>>q;
        q.push({1.0,st});
        vector<double>ans(n,0.0);
        while(!q.empty()){
             auto t=q.top();
            q.pop();
            if(t.second==end) {
                break;}
            for(auto it:adj[t.second]){
                double res=(double)(it.second*t.first);
                if(ans[it.first]<res){
                q.push({res,it.first});
                    ans[it.first]=res;
                }
            }
        }
        return ans[end];
    }
};