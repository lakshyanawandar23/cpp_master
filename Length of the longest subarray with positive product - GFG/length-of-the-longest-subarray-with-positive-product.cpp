//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int ans=0,l=0,t=0;
           long long int p=1;
           for(int i=0;i<n;i++){
                  if(arr[i]==0){
                 t=0, p=1;
                 continue;
              }
              else if(arr[i]>0){
                  p=p*1;
              }
              else {
                  p=p*-1;
              }
               t++;
               if(p>0){
                   ans=max(ans,t);
               }
           }
           t=0;
           p=1;
            for(int i=n-1;i>=0;i--){
                 if(arr[i]==0){
                 t=0, p=1;
                 continue;
              }
            else  if(arr[i]>0){
                  p=p*1;
              }
              else {
                  p=p*-1;
              }
               t++;
               if(p>0){
                   ans=max(ans,t);
               }
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends