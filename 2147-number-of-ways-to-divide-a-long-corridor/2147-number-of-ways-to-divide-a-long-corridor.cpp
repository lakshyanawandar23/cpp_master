class Solution {
public:
    int numberOfWays(string c) {
    long long    int n=c.size(),m=1e9+7,ans=1,s=0,p=0;
        if(n<=1) return 0;
        for(int i=0;i<n;i++){
            if(c[i]=='S'&&s==0&&p!=0){
                 ans=(ans%m*(i-p)%m)%m;
            }
             if(c[i]=='S')   s++;
            if(s==2) {
                s=0;
                p=i;
            }
        }
        return p==0||s!=0?0:ans;
    }
};