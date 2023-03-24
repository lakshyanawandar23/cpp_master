//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  bool solve(long long int mid,long  int a[],long int l,long  int m,long int h[],long  int n){
      long long int cnt=0;
      for(int i=0;i<n;i++){
          long long int curr=(long long int)(h[i]+(long long int)(a[i]*mid));
          if(curr>=l){
              cnt+=curr;
          }
      }
      return cnt>=m;
  }
    long buzzTime(long n, long m, long l, long h[], long a[])
    {
        // code here
        long long int low=1,high=1e9,ans=1e14;
        while(low<=high){
            long long int mid=(low+high)/2;
            if(solve(mid,a,l,m,h,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends