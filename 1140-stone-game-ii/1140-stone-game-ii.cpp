class Solution {
public:
    int dp[2][101][500];
    int solve(int player,int i,int m,vector<int>&p){
        if(i>=p.size() ) return 0;
        if(dp[player][i][m]!=-1) return dp[player][i][m];
        int sum=0,result;
        if(player) result=INT_MAX;
        else result=-1;
        for(int j=1;j<=2*m;j++){
            if(i+j-1<p.size()){
                sum+=p[i+j-1];
                if(player==0){
                result=max(result,sum+solve(player^1,i+j,max(m,j),p));
                }
                else {
                    result=min(result,solve(player^1,i+j,max(m,j),p));
                }
                }
        }
        return dp[player][i][m]=result;
    }
    int stoneGameII(vector<int>& p){
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,p);
    }
};