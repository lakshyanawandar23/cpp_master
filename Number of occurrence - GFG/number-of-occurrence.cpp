//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
   int solve1(int arr[],int n,int x){
        int ans=-1,l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==x){
                ans=max(ans,mid);
               l=mid+1;
            }
            else if(arr[mid]>x){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int solve(int arr[],int n,int x){
        int ans=INT_MAX,l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==x){
                ans=min(ans,mid);
               h=mid-1;
            }
            else if(arr[mid]>x){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int first=solve(arr,n,x);
	    int last=solve1(arr,n,x);
	    if(first==INT_MAX&&last==-1) return 0;
	    return (last-first+1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends