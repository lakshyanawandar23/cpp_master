class Solution {
public:
int solve(long long int curr,long long int next,long long int n){
    int cnt=0;
    while(curr<=n){
        cnt+=(next-curr);
        curr*=10;
        next=min(1LL*next*10,1LL*(n+1));
    }
    return cnt;
}
    int findKthNumber(int n, int k) {
     int curr=1;
     k--;
     while(k>0){
        int cnt=solve(curr,curr+1,n);
        if(cnt<=k){
            curr+=1;
            k-=cnt;
        }
        else {
            curr*=10;
            k-=1;
        }
     }   
       return curr;
    }
};