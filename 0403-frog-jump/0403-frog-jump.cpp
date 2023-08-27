class Solution {
public:
    bool solve(long long int i,vector<int>&s,vector<vector<long long int>>&dp,unordered_map<int,int>&m,long long int prev){
        if(i==s.size()-1){
            return true;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        for(long long int j=prev-1;j<=prev+1;j++){
            if(j>0&&m.find(j+s[i])!=m.end()){
                if(solve(m[s[i]+j],s,dp,m,j)){
                    return dp[i][prev]=true;
                }
            }
        }
        return dp[i][prev]=false;
    }
    bool canCross(vector<int>& s) {
     long long    int n=s.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(n+1,-1));
        unordered_map<int,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        return solve(0,s,dp,m,0);
    }
};