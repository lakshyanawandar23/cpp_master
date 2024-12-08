class Solution {
public:
   int dp[100001][3];
    int binary(vector<pair<pair<int,int>,int>>&v,int end){
        int l=0,r=v.size()-1,result=v.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid].first.first>end){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
            return result;
        
    }
    int solve(int i,int prev,vector<pair<pair<int,int>,int>>&v,int k){
        if(k==0) return 0;
         if(i>=v.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int pick=0,no=0;
       no=0+solve(i+1,prev,v,k);
    int idx=binary(v,v[i].first.second);
           // cout<<v[i].second<<endl;
           pick=v[i].second+solve(idx,v[i].first.second,v,k-1);
        return dp[i][k]= max(pick,no);
    }
    int maxTwoEvents(vector<vector<int>>& e) {
        //states=> i,prev and k=2 max event you can pick
        vector<pair<pair<int,int>,int>>v;
        for(auto it:e){
         v.push_back({{it[0],it[1]},it[2]});
        }
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        int k=2;
        return solve(0,-1,v,k);
    }
};