class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void solve(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&g,int &n,int&m){
        if(i<0||j<0||i>=n||j>=m||vis[i][j]==1||g[i][j]=='0') return ;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            solve(x,y,vis,g,n,m);
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int n=g.size(),m=g[0].size(),cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&g[i][j]=='1'){
                  solve(i,j,vis,g,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};