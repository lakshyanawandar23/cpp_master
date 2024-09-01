class Solution {
public:
    int dp[101][1<<11];
    int solve(int idx,int mask,map<int,vector<int>>&mp){
        if(idx==0) return 0;
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        int ans=0,res=0;
    
        
        for(auto it:mp[idx] ){
          //  cout<<it<<endl;
            if((mask&(1<<it))) continue;
                //cout<<it<<endl;
                ans=max(ans,idx+solve(idx-1,mask|(1<<it),mp));
            
        }
          ans= max(ans,solve(idx-1,mask,mp));
       return  dp[idx][mask]=ans;
    }
    int maxScore(vector<vector<int>>& g) {
        map<int,vector<int>>mp;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                mp[g[i][j]].push_back(i);
            }
        }
        return solve(100,0,mp);
    }
};