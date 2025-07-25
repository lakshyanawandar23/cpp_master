class Solution {
public:
 int dfs(vector<vector<int>>&adj,int src,int par,vector<int>&in,vector<int>&out,vector<int>&subtree,vector<int>&num,int &time){
    int curr=num[src];
    in[src]=time++;
    int sum=0;
    for(auto it:adj[src]){
        if(it==par) continue;
     sum^=dfs(adj,it,src,in,out,subtree,num,time);
    }
    subtree[src]=curr^sum;
    out[src]=time;
    time++;
    return subtree[src];
 }
  bool check(int u,int v,vector<int>&in,vector<int>&out){
   return in[u]<in[v]&&out[u]>out[v];
  }
    int minimumScore(vector<int>& num, vector<vector<int>>& e) {
        int n=num.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);

        }
        vector<int>subtree(n,0);
        vector<int>in(n,0);
        vector<int>out(n,0);
        int time=0,tot=0;
        for(auto it:num){
            tot^=it;
        }
        dfs(adj,0,-1,in,out,subtree,num,time);
        int result=INT_MAX;
        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
                int x1,x2,x3;
                if(check(u,v,in,out)){
                        x1=subtree[v];
                        x2=subtree[u]^subtree[v];
                        x3=tot^x1^x2;
                }
                 else  if(check(v,u,in,out)){
                        x1=subtree[u];
                        x2=subtree[u]^subtree[v];
                        x3=tot^x1^x2;
                }
                else {
                    x1=subtree[v];
                    x2=subtree[u];
                    x3=tot^x1^x2;

                }
                result=min(result,(max({x1,x2,x3})-min({x1,x2,x3})));
            }
        }
        return result;
    }
};