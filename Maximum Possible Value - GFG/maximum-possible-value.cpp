//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> a, vector<int> b) {
        // code here
        int mn=INT_MAX;
        long long int ans=0,tot=0;
        for(int i=0;i<N;i++){
            if(b[i]%2!=0){
                b[i]--;
            }
            if(b[i]>1){
                mn=min(mn,a[i]);
            }
            tot+=b[i];
            ans+=(a[i]*b[i]);
        }
        if(tot%4!=0){
            ans-=(mn*2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends