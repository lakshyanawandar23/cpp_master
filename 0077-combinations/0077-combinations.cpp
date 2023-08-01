class Solution {
public:
    void solve(int &n,int k,vector<int>&v,vector<vector<int>>&ans,int i){
        if(k==0){
            ans.push_back(v);
            return ;
        }
        for(int j=i+1;j<=n;j++){
            v.push_back(j);
            solve(n,k-1,v,ans,j);
            v.pop_back();
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(n,k,v,ans,0);
        return ans;
    }
};