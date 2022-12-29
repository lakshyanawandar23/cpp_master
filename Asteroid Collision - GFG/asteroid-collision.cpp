//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int>&s) {
        // code here
        stack<int>p;
        vector<int>ans;
        for(int i=0;i<n;){
            if(p.size()>0&&p.top()>0&&s[i]<0){
                if(p.top()>abs(s[i])){
                    i++;
                }
                else if(p.top()==abs(s[i])){
                    p.pop();
                    i++;
                }
                else{
                    p.pop();
                }
            }
            else{
                p.push(s[i]);
                i++;
            }
        }
        while(!p.empty()){
            ans.push_back(p.top());
            p.pop();
        }
        reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends