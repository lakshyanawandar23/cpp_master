class Solution {
public:
    int dp[100001][2][3];
    int m=1e9+7;
  long long  int solve(int i,int n,int a,int l){
        if(i==n)  return 1;
        if(dp[i][a][l]!=-1) return dp[i][a][l];
       // ans+="P";
     long long   int ans=0;
        ans=((ans%m)+(solve(i+1,n,a,0)%m))%m;
        
        if(a<1){
            
            ans=((ans%m)+(solve(i+1,n,a+1,0)%m))%m;
            
        }
        if(l<2){
           ans=((ans%m)+(solve(i+1,n,a,l+1)%m))%m;
          //  ans.pop_back();
        }
       return  dp[i][a][l]=(ans)%m;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,0,0);
    }
};