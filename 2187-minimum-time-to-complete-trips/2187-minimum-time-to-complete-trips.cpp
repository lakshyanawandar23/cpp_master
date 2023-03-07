class Solution {
public:
    long long minimumTime(vector<int>& t, int s) {
        long long int l,h,res=INT_MAX;
      long long   int ans=INT_MAX;
        for(int i=0;i<t.size();i++){
            ans=min(ans,(long long int)t[i]);
        }
        h=ans*s;
        l=0;
        while(l<=h){
            long long int m=(l+h)/2;
            long long int cnt=0;
            for(int i=0;i<t.size();i++){
                cnt+=(m/t[i]);
            }
            if(cnt>=s){
                res=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
};