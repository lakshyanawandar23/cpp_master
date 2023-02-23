//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1000000007;
  int dx[2]={1,0};
  int dy[2]={0,1};
  int solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&g,int n,int m,vector<vector<int>>&dp){
      if(i==n-1&&j==m-1){
          return 1;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      vis[i][j]=1;
      int ans=0;
      for(int k=0;k<2;k++){
          int x=i+dx[k];
          int y=j+dy[k];
          if(x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==0&&g[x][y]==1){
              ans+=solve(x,y,vis,g,n,m,dp);
          }
      }
      vis[i][j]=0;
      return  dp[i][j]= ans%mod;
      
  }
    int uniquePaths(int n, int m, vector<vector<int>> &g) {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(g[0][0]==0||g[n-1][m-1]==0){
            return 0;
        }
      return   solve(0,0,vis,g,n,m,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends