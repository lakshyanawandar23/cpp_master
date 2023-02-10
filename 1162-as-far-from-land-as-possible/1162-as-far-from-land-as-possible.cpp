class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int maxDistance(vector<vector<int>>& g) {
        int ans=0,n=g.size();
        queue<pair<int,int>>q;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g.size();j++){
                if(g[i][j]==1){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
          ans=max(ans,dis[p.first][p.second]);
            for(int i=0;i<4;i++){
                int x=dx[i]+p.first;
                int y=dy[i]+p.second;
                if(x>=0&&y>=0&&x<n&&y<n&&g[x][y]==0&&dis[x][y]==INT_MAX){
                    dis[x][y]=dis[p.first][p.second]+1;
                    q.push({x,y});
                }
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};