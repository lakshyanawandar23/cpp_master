class Solution {
public:
bool isvalid(int x,int y,vector<vector<int>>&g){
        int n=g.size(),m=g[0].size();
        if(x<0||y<0||x>=n||y>=m){
            return false;}
      if(g[x][y]==0){
          return false;}
        return true;
        }
    void dfs(int i,int j, vector<vector<int>>&g){
      g[i][j]=0;
      int dx[4]={1,-1,0,0};
     int dy[4]={0,0,1,-1};
     for(int k=0;k<4;++k){
       int u=i+dx[k];
       int v=j+dy[k];
       if(isvalid(u,v,g)){
         dfs(u,v,g);
           }
         }
      }
        
        
        
    int numEnclaves(vector<vector<int>>& g) {
     int n=g.size(),m=g[0].size();
     for(int i=0;i<m;++i){
       if(g[0][i]==1){
           dfs(0,i,g);
           }
         }
        for(int i=0;i<n;++i){
            if(g[i][m-1]==1){
             dfs(i,m-1,g);
                }
            }
     for(int i=m-1;i>=0;--i){
         if(g[n-1][i]==1){
             dfs(n-1,i,g);
             }
         }
        for(int i=n-1;i>=0;--i){
            if(g[i][0]==1){
                dfs(i,0,g);
                }
            }
        int cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(g[i][j]==1){
                    cnt++;
                    }
                }
            }
        return cnt;
    }
};