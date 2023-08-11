//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 long long int dp[1001][1001];
 long long int solve(long long int i,long long int t ,int s[]){
  
     if(i<0){
         return 0;
     }
     if(t==0){
         return 1;
     }
     if(dp[i][t]!=-1){
         return dp[i][t];
     }
  long long int no=solve(i-1,t,s);
  long long int take=0;
   if(s[i]<=t){
       take=solve(i,t-s[i],s);
   }
   return dp[i][t]=take+no;
 }
    long long int count(int s[], long long int n,long long int t) {

        // code here.
         dp[n+1][t+1];
 
  for(long long int i=0;i<=n;++i){
      for(long long int j=0;j<=t;++j){
          dp[i][j]=-1;
      }
  }
        return solve(n-1,t,s);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends