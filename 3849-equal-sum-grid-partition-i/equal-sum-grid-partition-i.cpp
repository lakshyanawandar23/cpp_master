class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        long long int tot_sum=0;
        vector<vector<long long int>>r(n,vector<long long int>(m,0));
         vector<vector<long long int>>c(n,vector<long long int>(m,0));
         for(int i=0;i<n;i++){
           long long int sum1=0;
            for(int j=0;j<m;j++){
                tot_sum+=g[i][j];
             sum1+=g[i][j];
             r[i][j]=sum1;
             if(i>0) c[i][j]=g[i][j]+c[i-1][j];
             else c[i][j]=g[i][j];
             }
         }
       long long   int sum1=0;
         for(int i=0;i<n;i++){
           sum1+=r[i][m-1];
         long long  int tot=tot_sum-sum1;
          // cout<<sum1<<endl;
           if(tot==sum1) return true;
         }
        long long int sum2=0;
         for(int j=0;j<m;j++){
            sum2+=c[n-1][j];
          long long  int tot=tot_sum-sum2;
            if(tot==sum2) return true;
         }
         return false;

    }
};