class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        vector<int>adj[n];
        for(auto it:r){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
         //   set<int>s;
           // set<int>original;
     int cnt=adj[i].size();
            for(int j=i+1;j<n;j++){
                int res=0;
                for(auto it:adj[j]){
               if(it!=i){
                   res++;
               }
                }
            ans=max(ans,res+cnt);
           // s.clear();
        //    s.assign(original);
            //s.insert(original.begin(),original.end());
        }
        }
        return ans;
    }
};