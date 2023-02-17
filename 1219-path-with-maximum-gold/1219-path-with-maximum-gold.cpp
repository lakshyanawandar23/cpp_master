class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g,int n,int m){
      if(i<0||j<0||i==n||j==m||vis[i][j]==1){
            return 0;
        }
        if(g[i][j]==0){
            return INT_MIN;
        }
        vis[i][j]=1;
        int ans=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
                ans=max(ans,g[i][j]+solve(x,y,vis,g,n,m));
        }
        vis[i][j]=0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size(),ans=0;
                     vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]!=0){
                    ans=max(ans,solve(i,j,vis,g,n,m));
                }
            }
        }
        return ans;
    }
};