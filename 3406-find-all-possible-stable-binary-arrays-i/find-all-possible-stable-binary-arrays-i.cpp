class Solution {
public:
    int dp[201][201][2];
    int mod = 1e9+7;

    long long solve(int z,int o,int &l,int s){
        if(z==0 && o==0) return 1;

        if(dp[z][o][s]!=-1) return dp[z][o][s];

        long long zero=0,one=0;

        if(s==1){ // last was 1 → place 0
            for(int i=1;i<=min(l,z);i++){
                zero=(zero+solve(z-i,o,l,0))%mod;
            }
        }
        else{ // last was 0 → place 1
            for(int i=1;i<=min(l,o);i++){
                one=(one+solve(z,o-i,l,1))%mod;
            }
        }

        return dp[z][o][s]=(zero+one)%mod;
    }

    int numberOfStableArrays(int z, int o, int l) {
        memset(dp,-1,sizeof(dp));
        return (solve(z,o,l,0)+solve(z,o,l,1))%mod;
    }
};