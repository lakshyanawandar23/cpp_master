class Solution {
public:
    int ans;
    void solve(int &n,vector<int>&v,vector<vector<int>>&r,int i,int l){
        if(i==n){
            for(int j=0;j<v.size();j++){
                if(v[j]!=0){
                    return ;
                }
            }
            ans=max(ans,l);
            return ;
        }
        solve(n,v,r,i+1,l);
        v[r[i][0]]--;
        v[r[i][1]]++;
        solve(n,v,r,i+1,l+1);
           v[r[i][0]]++;
        v[r[i][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& r) {
        ans=0;
        vector<int>v(n,0);
        int m=r.size();
         solve(m,v,r,0,0);
        return ans;
    }
};