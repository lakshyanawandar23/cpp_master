class Solution {
public:
    int xorAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        int mod=1e9+7;
        for(auto it:q){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int p=it[3];
            while(l<=r){
                 long long int res= (1LL*(v[l]%mod)*(p%mod))%mod;
                 v[l]=res%mod;
                 l+=k;
            }
        }
            int ans=0;
            for(auto it:v){
                ans=ans^it;
            }
        return ans;

    }
};