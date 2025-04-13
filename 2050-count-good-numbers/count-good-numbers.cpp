class Solution {
public:
const int MOD = 1e9 + 7;

long long power(long long base, long long exp, int mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}
    int countGoodNumbers(long long n) {
        long long int a=n%2==0?n/2:(n/2)+1;
        long long int b=n/2;
        long long int four=1;
        long long int five=power(5,a,MOD);
        if(b>0) four=power(4,b,MOD);
      //  cout<<five<<" "<<four<<endl;
        return (five*four)%MOD;
    }
};