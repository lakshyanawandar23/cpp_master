class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,string &s){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=solve(i+1,j-1,dp,s);
        }
        return 0;
    }
    int countSubstrings(string s) {
        int cnt=0,n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                cnt+=solve(i,j,dp,s);
            }
        }
        return cnt;
    }
};