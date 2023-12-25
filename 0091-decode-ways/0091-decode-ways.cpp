class Solution {
public:
    int solve(vector<int>&dp,string&s,int &n,int i){
        if(s[i]=='0') return 0;
        if(i>=n-1){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
      int cnt=0;
        for(int j=0;j<=1;j++){
           string ans=s.substr(i,j+1);
            int res=stoi(ans);
            if(res>0&&res<27){
                cnt+=solve(dp,s,n,i+j+1);
            }
        }
        return dp[i]=cnt;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(dp,s,n,0);
        
    }
};