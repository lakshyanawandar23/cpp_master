class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>adj[n];
        vector<int>out(n,0);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
                out[p[i][0]]++;
            }
        queue<int>q;
         int cnt=0;
        for(int i=0;i<n;i++){
            if(out[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[p]){
                out[it]--;
                if(out[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==n;
    }
};