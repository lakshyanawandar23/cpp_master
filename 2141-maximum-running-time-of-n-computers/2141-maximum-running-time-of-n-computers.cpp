class Solution {
public:
    bool solve(vector<int>&s, int &n, long long int &m){
        long long int res=0;
        for(auto it:s){
            res+=min((long long int)it,m);
        }
        return res>=(long long int)(n*m);
    }
    long long maxRunTime(int n, vector<int>& s) {
        long long int ans=0,l=0,h=1e14,sum=0;
        for(auto it:s){
            sum+=it;
        }
     //   h=(sum)/s.size();
        while(l<=h){
         long long int m=(l+h)/2;
            if(solve(s,n,m)){
                ans=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
};