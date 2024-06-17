class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<=2) return true;
        for(int i=1;i<=sqrt(c);i++){
          int sub=c-(i*i);
          int s=sqrt(sub);
            if((s*s)==sub&&((i*i)+(s*s))==c) return true;
        }
        return false;
    }
};