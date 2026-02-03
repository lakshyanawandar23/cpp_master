class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        long long int ans=0;
        int n=g[0].size();
        vector<vector<long long int>>pre(2,vector<long long int>(n,0));
        for(int i=0;i<2;i++){
            long long int sum=0;
            for(int j=0;j<n;j++){
                if(j>0) pre[i][j]=g[i][j]+pre[i][j-1];
                else pre[i][j]=g[i][j];
            }
        }
       long long int idx=1e18;
        for(int i=0;i<n;i++){
        
      if(i>0) idx=min(idx,max((pre[0][n-1]-pre[0][i]),pre[1][i-1]));
        else idx=min(idx,max((pre[0][n-1]-pre[0][i]),1LL*0));
        }
         return idx;
    }
};