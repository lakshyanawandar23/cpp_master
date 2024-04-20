class Solution {
public:
    int dx[4]={1,1,0,0};
    int dy[4]={0,0,1,-1};
    void solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g,int &x,int &y,int &n,int &m){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int new_x=dx[k]+i;
            int new_y=dy[k]+j;
            if(new_x>=0&&new_y>=0&&new_x<n&&new_y<m&&vis[new_x][new_y]==0&&g[new_x][new_y]==1){
              x=max(x,new_x);
        y=max(y,new_y);
                solve(new_x,new_y,vis,g,x,y,n,m);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& g) {
        vector<vector<int>>v;
        int n=g.size(),m=g[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   vector<int>ans;
                if(g[i][j]==1&&vis[i][j]==0){
                    ans.push_back(i);
                    ans.push_back(j);
                    int x=i;
                    int y=j;
                    solve(i,j,vis,g,x,y,n,m);
                    ans.push_back(x);
                    ans.push_back(y);
                    v.push_back(ans);
                }
            }
        }
        return v;
    }
};