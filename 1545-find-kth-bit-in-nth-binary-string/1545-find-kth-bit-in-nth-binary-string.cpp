class Solution {
public:
    int solve(int n,int k){
        if(n==0) return 0;
        long long int r=pow(2,n);
        if(r==k) return 1;
        if(r<k){
            return (solve(n-1,r-(k%r)))^1;
        }
        else {
            return solve(n-1,k);
        }
    }
    char findKthBit(int cnt, int k) {
      long long  int n=1,ans=0;
        while(ans<k){
         ans=pow(2,n);
            n++;
        }
        if(ans==k) return '1';
        long long int res=pow(2,n-1);
        return solve(n-1,k)+'0';   
    }
};