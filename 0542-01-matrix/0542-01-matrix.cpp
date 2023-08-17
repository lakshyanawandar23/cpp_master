class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=dx[k]+p.first;
                int y=dy[k]+p.second;
                if(x>=0&&y>=0&&x<n&&y<m&&mat[x][y]!=0){
                    if(dis[x][y]>1+dis[p.first][p.second]){
                        q.push({x,y});
                        dis[x][y]=1+dis[p.first][p.second];
                    }
                }
            }
        }
        return dis;
    }
};