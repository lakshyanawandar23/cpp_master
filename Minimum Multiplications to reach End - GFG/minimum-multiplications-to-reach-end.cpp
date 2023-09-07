//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int s, int e) {
        // code here
        queue<pair<int,int>>q;
     vector<int>vis(100001,INT_MAX);
        vis[s]=0;
        q.push({s,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p.first==e){
                return p.second;
            }
            for(int i=0;i<arr.size();i++){
                int x=(p.first*arr[i])%100000;
                if(vis[x]>p.second+1){
                    q.push({x,p.second+1});
                    vis[x]=p.second+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends