class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&dis,int cnt,int i,int k,int vis[],int src){
      vis[i]=1;
        for(auto it:adj[i]){
          //  cout<<it<<endl;
            if(vis[it]==0&&cnt+1<=k){
                dis[src]+=1;
             //   cout<<it<<endl;
              dfs(adj,dis,cnt+1,it,k,vis,src);       
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
        int n=e1.size(),m=e2.size();
         vector<vector<int>>adj1(n+1);
        vector<vector<int>>adj2(m+1);
        vector<int>dis1(n+1,0);
        vector<int>dis2(m+1,0);
        for(auto it:e1){
          adj1[it[0]].push_back(it[1]);
          adj1[it[1]].push_back(it[0]);
        }
          for(auto it:e2){
          adj2[it[0]].push_back(it[1]);
          adj2[it[1]].push_back(it[0]);
        }
        int v[n+1];
      int vis[m+1];
       for(int i=0;i<=n;i++){
          memset(v,0,sizeof(v));
           dfs(adj1,dis1,0,i,k,v,i);
       }
        int maxi=0;
        for(int j=0;j<=m;j++){
            memset(vis,0,sizeof(vis));
            dfs(adj2,dis2,0,j,k-1,vis,j);
            maxi=max(maxi,dis2[j]);
        }
      vector<int>ans;
        for(int i=0;i<=n;i++){
            int res=dis1[i]+maxi+1;
            if(k>0) {res++;}
            ans.push_back(res);
        }
        return ans;
    }
};