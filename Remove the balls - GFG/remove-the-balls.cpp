//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> c, vector<int> r) {
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            if(!s.empty()&&s.top().first==c[i]&&s.top().second==r[i]){
                while(!s.empty()&&s.top().first==c[i]&&s.top().second==r[i]){
                    s.pop();
                }
            }
            else{
                s.push({c[i],r[i]});
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends