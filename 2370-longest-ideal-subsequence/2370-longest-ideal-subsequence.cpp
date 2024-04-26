class Solution {
public:
    // if we have to find subsequence generally the probelm is of dp and recursion 
    int solve(string &s,int &k,int i,char prev,vector<vector<int>>&dp){
       if(i==s.size()){
           if(prev=='`'||abs((s[i]-'a')-(prev-'a'))<=k) return 1;
           return 0;
       }
        if(dp[i][prev-'`']!=-1) return dp[i][prev-'`'];
        int pick=0,no=0;
        no=0+solve(s,k,i+1,prev,dp);
        if(prev=='`'||abs((s[i]-'a')-(prev-'a'))<=k){
            pick=1+solve(s,k,i+1,s[i],dp);
        }
        return dp[i][prev-'`']=max(pick,no);
    }
    int longestIdealString(string s, int k) {
       //it have two states changing i and prev
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(28,-1));
        return solve(s,k,0,'`',dp);
    }
};