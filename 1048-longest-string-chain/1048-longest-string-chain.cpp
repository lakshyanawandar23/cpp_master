class Solution {
public:
    static bool cmp(string&a,string &b){
        return a.size()<b.size();
    }
    bool check(int i,int p,vector<string>&w){
        int j=0,k=0,x=w[i].size(),y=w[p].size();
        if(x>=y&&(x-y)!=1)return false;
        while(j<w[i].size()&&k<w[p].size()){
            if(w[i][j]==w[p][k]){
                k++;
            }
            j++;
        }
        return k==w[p].size();
    }
    int solve(int prev,int i,vector<vector<int>>&dp,int &n,vector<string>&w){
         if(i==n){
             return 0;
         }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int no=0+solve(prev,i+1,dp,n,w);
        int pick=0;
        if(prev==-1||check(i,prev,w)){
            pick=1+solve(i,i+1,dp,n,w);
        }
        return dp[i][prev+1]=max(no,pick);
    }
    int longestStrChain(vector<string>& w) {
    //    unordered_map<int,int>m;
        int n=w.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(begin(w),end(w),cmp);
        return solve(-1,0,dp,n,w);
    }
};