class Solution {
public:
    long long coloredCells(int n) {
        long long int ans=0,cnt=1;
        while(n>1){
            ans+=(cnt*2);
            cnt+=2;
            n--;
        }
        ans+=cnt;
        return ans;
    }
};