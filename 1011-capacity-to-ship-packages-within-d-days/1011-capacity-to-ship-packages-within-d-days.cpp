class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int l=0,h=0,ans;
        for(int i=0;i<w.size();i++){
            h+=w[i];
            l=max(l,w[i]);
        }
        while(l<=h){
            int m=(l+h)/2;
            int sum=0,r=1,i;
            for( i=0;i<w.size();i++){
                if(sum+w[i]<=m){
                    sum+=w[i];
                }
                else {
                    r++;
                    sum=w[i];
                }
            }
            if(r<=d){
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