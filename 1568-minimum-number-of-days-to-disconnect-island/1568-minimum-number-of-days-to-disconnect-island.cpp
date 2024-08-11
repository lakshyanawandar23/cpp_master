class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n,m;
    void solve(int i,int j,vector<vector<int>>&g,vector<vector<int>>&vis){
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            //   cout<<i<<" "<<j<<endl;
            if(x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==0&&g[x][y]==1){
           //        cout<<x<<" "<<y<<endl;
                vis[x][y]=1;
                solve(x,y,g,vis);
            }
        }
    }
    int minDays(vector<vector<int>>& g) {
         n=g.size(),m=g[0].size();
        int res=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&g[i][j]) {
                    solve(i,j,g,vis);
                    res++;
                }
            }
        }
        if(res>1||res==0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
        int cnt=0,ans=0;
                    g[i][j]=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
      // fill(vis.begin(),vis.end(),0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1) ans++;
                if(g[i][j]==1&&vis[i][j]==0){
                //    cout<<i<<" "<<j<<endl;
                    vis[i][j]=1;
                  solve(i,j,g,vis);
                    cnt++;
                }
            }
        }
        if(cnt>1||cnt==0) return 1;
                 //   if(cnt>=2) return 0;
                    g[i][j]=1;
                }
            }
        }
        return 2;
    }
};