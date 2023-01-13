//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int n, vector<int> arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:arr){
            q.push(it);
        }
        int sum=0;
        while(q.size()>1){
            int u=q.top();
            q.pop();
            int v=q.top();
            q.pop();
            int res=u+v;
            sum+=(res);
            q.push(res);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends