class Solution {
public:
    int maxCoins(vector<int>& p) {
        int n=p.size();
        int ans=0,i=0,j=1,k=2,cnt=n/3;
        sort(p.begin(),p.end(),greater<int>());
        while(cnt>0){
            ans+=p[j];
           // i=(i+3);
            j=(j+2);
           // k=(k+3);
            cnt--;
        }
        return ans;
    }
};