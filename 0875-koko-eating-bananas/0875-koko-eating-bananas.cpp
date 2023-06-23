class Solution {
public:
   long long int solve(vector<int>&p,long long int &m){
     long long   int sum=0;
        for(int i=0;i<p.size();i++){
            if(p[i]%m==0){
                sum+=(p[i]/m);
            }
            else {
   sum+=(p[i]/m+1);
            }
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& p, int h) {
       int low=1,high;
      long long  int ans=1e9;
        for(auto it:p){
            high=max(high,it);
        }
        while(low<=high){
          long long  int m=(long long int )(low+high)/2;
       long long  int res=solve(p,m);
            if(res<=h){
                ans=min(ans,m);
                    high=m-1;
            }
            else {
               low=m+1;         
            }
        }
        return ans;
    }
};