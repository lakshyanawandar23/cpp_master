class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
   int n=g.size(),m=g[0].size();
    queue<pair<int,int>>q;
       if(g[0][0]==0){
           q.push({0,0});
         g[0][0]=1;
           }
        
   while(!q.empty()){
     int u=q.front().first;
     int v=q.front().second;
       q.pop();
     if(u==n-1&&v==m-1){
         return g[u][v];}
     int dx[8]={1,-1,0,0,1,-1,-1,1};
    int dy[8]={0,0,1,-1,1,-1,1,-1};
     for(int i=0;i<8;++i){
  int x=u+dx[i];
  int y=v+dy[i];
 if(x>=0&&y>=0&&x<n&&y<m&&g[x][y]==0){
   g[x][y]=g[u][v]+1;
     q.push({x,y});
     }
     }
  }
    return -1;

    }
};