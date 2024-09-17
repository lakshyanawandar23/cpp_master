class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int swimInWater(vector<vector<int>>& g) {
        int n=g.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({g[0][0],{0,0}});
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
     //   dis[0][0]=g[0][0];
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(p.second.first==n-1&&p.second.second==n-1) return p.first;
            for(int k=0;k<4;k++){
                int x=dx[k]+p.second.first;
                int y=dy[k]+p.second.second;
                if(x>=0&&y>=0&&x<n&&y<n&&vis[x][y]==0){
                    g[x][y]=max(p.first,g[x][y]);
           q.push({g[x][y],{x,y}});
                    vis[x][y]=1;
                }
            }
        }
        return -1;
    }
};