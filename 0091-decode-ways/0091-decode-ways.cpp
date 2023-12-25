class Solution {
public:
    int solve(vector<int>&dp,string&s,int &n,int i){
        if(i==n){
            return 1;
        }
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
      int cnt=0;
    cnt+=solve(dp,s,n,i+1);
        if(i+1<n&&s.substr(i,2)<="26"){
            cnt+=solve(dp,s,n,i+2);
        }
        return dp[i]=cnt;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(dp,s,n,0);
        
    }
};