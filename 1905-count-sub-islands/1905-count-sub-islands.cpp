class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
        bool dfs1(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g1,set<pair<int,int>>&s){
        vis[i][j]=1;
      //  s.insert({i,j});
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0&&y>=0&&x<g1.size()&&y<g1[0].size()&&vis[x][y]==-1&&g1[x][y]==1){
              if(s.find({x,y})!=s.end()){  
           return  dfs1(x,y,vis,g1,s);
            }
                else return false;
        }
    }
            return true;
        }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g1,vector<vector<int>>&g2,int &f){
        vis[i][j]=1;
        if(g1[i][j]==0) f=0;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0&&y>=0&&x<g1.size()&&y<g1[0].size()&&vis[x][y]==-1&&g2[x][y]==1){
                dfs(x,y,vis,g1,g2,f);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int cnt=0,n=g1.size(),m=g1[0].size();
    //    set<pair<int,int>>s;
        vector<vector<int>>vis(n,vector<int>(m,-1));
     //   vector<vector<int>>vis1(n,vector<int>(m-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int flag=1;
                if(g2[i][j]==1&&vis[i][j]==-1){
                    dfs(i,j,vis,g1,g2,flag);
                    cnt+=flag;
                }
            }
        }
        return cnt;
    }
};