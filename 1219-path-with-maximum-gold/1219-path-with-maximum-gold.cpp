class Solution {
public:
    int ans;
    int solve(vector<vector<int>>&g,vector<vector<int>>&vis,int i,int j,int &n ,int &m){
        if(i<0||j<0||i>=n||j>=m||vis[i][j]==1||g[i][j]==0) return 0;
        vis[i][j]=1;
        int l=solve(g,vis,i,j-1,n,m);
        int r=solve(g,vis,i,j+1,n,m);
        int d=solve(g,vis,i+1,j,n,m);
        int u=solve(g,vis,i-1,j,n,m);
        vis[i][j]=0;
        return  g[i][j]+max({l,r,u,d});
    }
    int getMaximumGold(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        ans=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(g[i][j]>=0){
                  vector<vector<int>>vis(n,vector<int>(m,0));
                  ans=max(ans,solve(g,vis,i,j,n,m));
              }
          }
        }
        return ans;
    }
};