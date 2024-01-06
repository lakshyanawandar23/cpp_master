class Solution {
public:
     int solve(vector<vector<int>>&v,vector<int>&dp,int i,int &n){
         if(i>=v.size()){
             return 0;
         }
         if(dp[i]!=-1){
             return dp[i];
         }
         int pick=0,no=0;
            no=0+solve(v,dp,i+1,n);
         vector<int> p={v[i][1],0,0};
         int idx=lower_bound(v.begin(),v.end(),p)-v.begin();
             pick=v[i][2]+solve(v,dp,idx,n);
      
      return   dp[i]=max(no,pick);
     }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=s.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
           v.push_back({s[i],e[i],p[i]});
        }
        sort(v.begin(),v.end());
        vector<int>dp(50000,-1);
        return solve(v,dp,0,n);
    }
};