class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        for(int i=0;i<32;i++){
            long long int x=pow(2,i);
            if(x==n&&i%2==0) return true;
        }
        return false;
    }
};