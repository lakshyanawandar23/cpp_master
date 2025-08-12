class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
       // cout<<n&&(n-1)<<endl;
    int check=(n-1)&n;
   // cout<<check<<endl;
    return check==0;
    }
};