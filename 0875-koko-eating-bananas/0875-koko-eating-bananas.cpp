class Solution {
public:
    int minEatingSpeed(vector<int>& p, int t) {
        int l=1,h,ans=INT_MAX;
        for(auto it:p){
            h=max(h,it);
        }
        while(l<=h){
            int m=(l+h)/2;
        long long  int cnt=0;
            for(int i=0;i<p.size();i++){
                if(p[i]%m==0){
                    cnt+=(p[i]/m);
                }
                else{
                    cnt+=(p[i]/m+1);
                }
            }
            if(cnt<=t){
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