class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int dx1[2]={1,0};
    int dy1[2]={0,1};
    bool check(int mid,vector<vector<int>>&dis,int &n,int i,int j,vector<vector<int>>&vis){
      //out<<i<<" "<<j<<" "<<mid<<endl;
        if(i<0||j<0||i>=n||j>=n||dis[i][j]<mid||vis[i][j]==1) return false;
        if(i==n-1&&j==n-1) return true;
        vis[i][j]=1;
        // for(int k=0;k<4;k++){
        //     int x=i+dx[k];
        //     int y=j+dy[k];
        //     if(check(mid,dis,n,x,y)){
        //         return true;
        //     }
        // }
        bool a=check(mid,dis,n,i+1,j,vis);
          bool b=check(mid,dis,n,i-1,j,vis);
          bool c=check(mid,dis,n,i,j+1,vis);
          bool d=check(mid,dis,n,i,j-1,vis);
        return a||b||c||d;
    }
    int maximumSafenessFactor(vector<vector<int>>& g) {
      int n=g.size();
      vector<vector<int>>dis(n,vector<int>(n,1e9));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int ans=0,l=1,h=1e9;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=p.first+dx[k];
                int y=p.second+dy[k];
                if(x>=0&&y>=0&&x<n&&y<n&&dis[x][y]==1e9){
                    dis[x][y]=dis[p.first][p.second]+1;
                   h=max(h,dis[x][y]+1);
                    q.push({x,y});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dis[i][j]<<endl;
        //     }
        // }
        while(l<h){
            int mid=(l+h)/2;
           // cout<<l<<""<<h<<endl;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(check(mid,dis,n,0,0,vis)){
              //  cout<<ans<<endl;
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        return ans;
    }
};