class Solution {
public:
    int solve(vector<vector<int>>&g,vector<vector<int>>&dp,int i,int j){
        if(i==g.size()){
           // cout<<"hello"<<endl;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int y=0;y<g[0].size();y++){
            if(y!=j){
            //    cout<<y<<endl;
            ans=min(ans,g[i][y]+solve(g,dp,i+1,y));
        }
        }
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& g) {
        int n=g[0].size();                                                             vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=1e9;
        for(int j=0;j<n;j++){
            ans=min(ans,g[0][j]+solve(g,dp,1,j));
        }
        return ans;
    }
};