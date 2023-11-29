class Solution {
public:
    int dp[4][3][5001];
    int dx[8]={-2,-2,2,2,1,1,-1,-1};
    int  dy[8]={-1,1,1,-1,2,-2,2,-2};
    int mod=1e9+7;
    int solve(int i,int j,vector<vector<int>>&mat,int n){
       if(i<0||j<0||i>=4||j>=3||(i==3&&j==0)||(i==3&&j==2)){
        //   cout<<i<<" "<<j<<endl;
            return 0;
        }
        if(n==0) {
          //  cout<<i<<" "<<j<<endl;
            return 1;
        }
       
        if(dp[i][j][n]!=-1){
     return dp[i][j][n];
         }
        int res=0;
        for(int k=0;k<8;k++){
            int x=i+dx[k];
            int y=j+dy[k];
           // cout<<x<<" "<<y<<endl;
            res=((res%mod)+(solve(x,y,mat,n-1))%mod)%mod;
        }
        return dp[i][j][n]=res%mod;
    }
    int knightDialer(int n) {
        vector<vector<int>>mat(4,vector<int>(3,-1));
        int cnt=1,ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((i!=3&&j!=0)||(i!=3)&&j!=2){
                    mat[i][j]=(cnt);
                    cnt++;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        mat[3][1]=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                 if(mat[i][j]!=-1){
                     ans=((ans%mod)+(solve(i,j,mat,n-1))%mod)%mod;
                 }
       }
        }
        return ans;
    }
};