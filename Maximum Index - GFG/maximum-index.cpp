//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>l(n);
        vector<int>r(n);
        int ans=INT_MIN;
        l[0]=arr[0];
        r[n-1]=arr[n-1];
        // finding the leftmost min;
        for(int i=1;i<n;i++){
         l[i]=min(arr[i],l[i-1]);   
        }
        //finding the rightmost max;
         for(int i=n-2;i>=0;i--){
            r[i]=max(arr[i],r[i+1]);
         }
         int i=0,j=0;
         while(j<n&&i<n){
            if(l[i]<=r[j]){
            ans=max(ans,(j-i));
            j++;
            }
            else {
            i++;}
        }
        return ans;
        
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends