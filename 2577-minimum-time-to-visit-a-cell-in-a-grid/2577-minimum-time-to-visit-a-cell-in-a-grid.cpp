class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int minimumTime(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size(),cnt=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>d(n,vector<int>(m,INT_MAX));
        d[0][0]=0;
        if(g[0][1]<=1||g[1][0]<=1) cnt=1;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            int dis=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if(x==n-1&&y==m-1) return p.first;
            for(int k=0;k<4;k++){
                int i=x+dx[k];
                int j=y+dy[k];
           if(i>=0&&j>=0&&i<n&&j<m&&d[i][j]>1+dis){
               if(dis+1>=g[i][j]){
                   d[i][j]=1+dis;
                   q.push({dis+1,{i,j}});
               }
               else if(cnt>0){
                   int diff=g[i][j]-dis;
                   if(diff%2==0){
                       d[i][j]=g[i][j]+1;
                       q.push({d[i][j],{i,j}});
                       
                   }
                   else {
                       d[i][j]=g[i][j];
                       q.push({d[i][j],{i,j}});
                   }
               }
           }
            }
        }
        return -1;
    }
};