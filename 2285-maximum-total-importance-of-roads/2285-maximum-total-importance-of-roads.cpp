class Solution {
public:

    long long maximumImportance(int n, vector<vector<int>>& r) {
        vector<int>adj[n+1];
        vector<int>indegree(n,0);
     long long int cnt=1,ans=0;
        for(auto v:r){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
            indegree[v[1]]++;
        }
        sort(indegree.begin(),indegree.end());
        for(int i=0;i<n;i++){
           ans+=(indegree[i]*cnt);
            cnt++;
        }
     
        return ans;
    }
};