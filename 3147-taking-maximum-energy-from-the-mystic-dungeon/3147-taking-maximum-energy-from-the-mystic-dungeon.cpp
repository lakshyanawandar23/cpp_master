class Solution {
public:
    int solve(int i,vector<vector<int>>&dp,vector<int>&e,int &k,int f){
        if(i==e.size()-1) return e[i];
        if(i>=e.size()) return 0;
        if(dp[i][f]!=-1) return dp[i][f];
        int pick=INT_MIN,no=INT_MIN;
        if(f==1){
        pick=e[i]+solve(i+k,dp,e,k,1);
        }
        else {
        no=max(0+solve(i+1,dp,e,k,0),e[i]+solve(i+k,dp,e,k,1));
        }
        return dp[i][f]=max(no,pick);
    }
    int maximumEnergy(vector<int>& e, int k) {
        int n=e.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,dp,e,k,0);
    }
};