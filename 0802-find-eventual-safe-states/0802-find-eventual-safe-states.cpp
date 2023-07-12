class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
      int n=g.size();
        vector<int>adj[n];
        vector<int>out(n,0);
        for(int i=0;i<n;i++){
            for(auto val:g[i]){
                //adj[].push_back(g[i][j]);
               adj[val].push_back(i);
                out[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
       if(out[i]==0){
           q.push(i);
       }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            ans.push_back(p);
        for(auto it:adj[p]){
            out[it]--;
            if(out[it]==0){
                q.push(it);
            }
        }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};