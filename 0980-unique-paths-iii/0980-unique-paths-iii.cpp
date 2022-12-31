class Solution {
public:
    int ans;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void solve(int i,int j,vector<vector<int>>&vis,int x,int y,int &cnt,vector<vector<int>>&g){
        if(i==x&&y==j&&cnt==-1){
            ans++;
            return ;
        }
        vis[i][j]=1;
        cnt--;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int  ny=j+dy[k];
            if(nx>=0&&ny>=0&&nx<g.size()&&ny<g[0].size()&&vis[nx][ny]==0){
                 solve(nx,ny,vis,x,y,cnt,g);
            }
        }
        vis[i][j]=0;
        cnt++;
    }
    int uniquePathsIII(vector<vector<int>>& g) {
        ans=0;
        int cnt=0,x,y,ei,ej;
        vector<vector<int>>vis(g.size(),vector<int>(g[0].size(),0));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    x=i;
                    y=j;
                    vis[i][j]=1;
                }
                else if(g[i][j]==2){
                    ei=i;
                    ej=j;
                }
                else if(g[i][j]==-1){
                    vis[i][j]=1;
                }
                else{
                    cnt++;
                }
            }
        }
        solve(x,y,vis,ei,ej,cnt,g);
        return ans;
    }
};