//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> l, int n) {
        // Code here
        vector<pair<int,int>>v;
        for(int i=0;i<l.size();i++){
            v.push_back({l[i][0],1});
            v.push_back({l[i][1]+1,-1});
        }
        sort(v.begin(),v.end());
        int cnt=0,ans=0;
        for(int i=0;i<v.size();i++){
      cnt+=v[i].second;
      ans=max(ans,cnt);
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
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends