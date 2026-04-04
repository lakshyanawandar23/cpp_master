class Solution {
public:
    int dp[501][501][3];

    int solve(int i, int j, vector<vector<int>>& v, int &n, int &m, int k) {
        if (i == n - 1 && j == m - 1) return k>0?max(0,v[i][j]):v[i][j];
        if (i < 0 || j < 0 || i >= n || j >= m ) return -1e7;

   //     if (i == n - 1 && j == m - 1) return k>0?max(0,v[i][j]):v[i][j];
    

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
              
        int take=v[i][j]+max(solve(i+1,j,v,n,m,k),solve(i,j+1,v,n,m,k));
        int skip=-1e7;
        if(v[i][j]<0&&k>0){
            int d=solve(i+1,j,v,n,m,k-1);
            int r=solve(i,j+1,v,n,m,k-1);
            skip=max(d,r);
        }
     return dp[i][j][k]=max(skip,take);
    }

    int maximumAmount(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int k = 2; // allowed skips (adjust if needed)
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=INT_MIN;
            }
        }
       }
        return solve(0, 0, v, n, m, k);
    }
};