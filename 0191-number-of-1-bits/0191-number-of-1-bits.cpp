class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
     //   cout<<n%10<<endl
        while(n>0){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};