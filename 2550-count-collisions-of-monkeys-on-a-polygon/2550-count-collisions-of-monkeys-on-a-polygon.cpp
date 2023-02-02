class Solution {
public:
  long long  int power(long long x,  int y, int p)
{
  long long int   res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
    int monkeyMove(int n) {
        long long int ans=power(2,n,1000000007)-2;
        return (ans+1000000007)%1000000007;
    }
};