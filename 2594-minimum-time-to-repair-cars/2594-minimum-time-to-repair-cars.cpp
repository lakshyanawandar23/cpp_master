class Solution {
public:
    bool solve(long long int m,vector<int>&r,int c){
        long long int cnt=0;
        for(int i=0;i<r.size();i++){
            cnt+=sqrt(m/r[i]);
        }
        return cnt>=c;
    }
    long long repairCars(vector<int>& r, int c) {
        long long int l=0,h=1e14,ans=0;
        while(l<=h){
            long long int m=(l+h)/2;
            if(solve(m,r,c)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};