class Solution {
public:
    int concatenatedBinary(int n) {
      long long   int ans=0,mod=1e9+7;
        for(int i=1;i<=n;i++){
            int digits=log2(i)+1;
            ans=(((ans<<digits)%mod)+i)%mod;
        }
        return ans;
    }
};