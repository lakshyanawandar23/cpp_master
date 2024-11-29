class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int minimumObstacles(vector<vector<int>>& g) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        int n=g.size(),m=g[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(p.second.first==n-1&&p.second.second==m-1) return p.first;
            int i=p.second.first;
            int j=p.second.second;
            for(int k=0;k<4;k++){
                int x=dx[k]+i;
                int y=dy[k]+j;
                if(x>=0&&y>=0&&x<n&&y<m&&p.first+g[x][y]<dis[x][y]){
                        q.push({p.first+g[x][y],{x,y}});
                        dis[x][y]=p.first+g[x][y];
                }
            }
        }
        return -1;
    }
};