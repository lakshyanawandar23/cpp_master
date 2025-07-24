class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
  void dfs(int i,int j,vector<vector<int>>&g,vector<vector<int>>&vis,long long int &sum){
       vis[i][j]=1;
       sum+=g[i][j];
       for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<g.size()&&y<g[0].size()&&vis[x][y]==0&&g[x][y]>0){
            dfs(x,y,g,vis,sum);
        }
       }
       return ;
  }
    int countIslands(vector<vector<int>>& g, int k) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(vis[i][j]==0&&g[i][j]>0){
               long long  int sum=0;
                dfs(i,j,g,vis,sum);
                //cout<<sum<<endl;
                if(sum%k==0) cnt++;
               }
            }
        }
        return cnt;
    }
};