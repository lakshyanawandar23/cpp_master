class Solution {
public:
    int ans;
    void solve(int i,int &ans,vector<int>&c,int &k,vector<int>&v,int &n){
        if(i==n){
            int res=0;
            for(int j=0;j<k;j++){
                res=max(res,v[j]);
            }
            ans=min(ans,res);
            return ;
        }
        for(int j=0;j<k;j++){
            int res=c[i];
            v[j]+=(res);
            solve(i+1,ans,c,k,v,n);
            v[j]-=res;
        }
    }
    int distributeCookies(vector<int>& c, int k) {
        ans=INT_MAX;
        int n=c.size();
        vector<int>v(k,0);
         solve(0,ans,c,k,v,n);
        return ans;
    }
};