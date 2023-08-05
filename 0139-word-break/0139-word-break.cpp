class Solution {
public:
    int solve(string s,set<string>&v,int i,vector<int>&dp){
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string t;
        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(v.find(t)!=v.end()){
               if(solve(s,v,j+1,dp)) return dp[i]=1 ;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& w) {
        set<string>v;
        vector<int>dp(s.size()+1,-1);
        for(auto it :w){
            v.insert(it);
        }
        return solve(s,v,0,dp);
    }
};