class Solution {
public:
    int dx[3]={-1,0,1};
    int dp[71][71][71];
    int solve(int i,int j1,int j2,vector<vector<int>>&g,int &n,int &m){
        if(i==n-1){
            if(j1==j2){
                return g[i][j1];
            }
                return g[i][j1]+g[i][j2];
            
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
       int ans=0;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
            int x1=i+1;
            int y1=dx[k]+j1;
            int y2=dx[l]+j2;
            if(y1>=0&&y1<m&&y2>=0&&y2<m){
              //  cout<<x1<<" "<<y1<<" "<<y2<<endl;
                if(j1==j2){
                    ans=max(ans,g[i][j1]+solve(x1,y1,y2,g,n,m));
                }
                else {
                    ans=max(ans,g[i][j1]+g[i][j2]+solve(x1,y1,y2,g,n,m));
                }
            }
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,g,n,m);
    }
};