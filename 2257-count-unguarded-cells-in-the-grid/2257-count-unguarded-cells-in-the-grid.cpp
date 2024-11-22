class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        int cnt=0,rem;
      rem=(m*n)-(g.size()+w.size());
       vector<vector<int>>vis(m,vector<int>(n,1));
      set<pair<int,int>>s;
        for(auto it:w){
           vis[it[0]][it[1]]=-1;
        }
        for(auto it:g){
            vis[it[0]][it[1]]=0;
        }
        for(int i=0;i<g.size();i++){
            for(int k=0;k<4;k++){
            int x1=g[i][0];
            int y1=g[i][1];
                while(1){
                    int x=dx[k]+x1;
                    int y=dy[k]+y1;
                    if(x<0||y<0||x>=m||y>=n||vis[x][y]==-1||vis[x][y]==0){
                        break;
                    }
                    else {
                        x1=x;
                        y1=y;
                        vis[x][y]=5;
                    }
                 //   cout<<x<<" "<<y<<endl;
                    
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};