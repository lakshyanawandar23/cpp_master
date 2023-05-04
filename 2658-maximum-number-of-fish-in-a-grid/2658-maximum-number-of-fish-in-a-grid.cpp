class Solution {
public:
    int ans;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    bool isvalid(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g){
         int n=g.size(),m=g[0].size();
        if(i<0||j<0||i>=n||j>=m) return false;
        if(vis[i][j]==1||g[i][j]==0) return false;
        return true;
    }
    void solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g,int &res){
        vis[i][j]=1;
        res+=g[i][j];
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(isvalid(x,y,vis,g)){
             solve(x,y,vis,g,res);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& g) {
        ans=0;
        int n=g.size(),m=g[0].size();
        if(n==1&&m==1){
            return g[0][0];
        }
        for(int i=0;i<n;i++){
            vector<vector<int>>vis(n,vector<int>(m,0));
            for(int j=0;j<m;j++){
                int res=0;
                if(g[i][j]>=1){
                    solve(i,j,vis,g,res);
                   ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};