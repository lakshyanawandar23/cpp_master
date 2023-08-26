//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n=s.size(),j=0,ans=-1,i=0;
      unordered_map<char,int>m;
      while(i<n){
          m[s[i]]++;
          while(m.size()>k&&j<=i){
              m[s[j]]--;
              if(m[s[j]]==0){
                  m.erase(s[j]);
              }
              j++;
          }
          if(m.size()==k){
              ans=max(ans,(i-j+1));
          }
          i++;
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends