//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        unordered_map<char,int>m;
        int i=0,j=s.size()-1,f=1;
        while(i<s.size()){
            m[s[i]]++;
            i++;
        }
        i=0;
        while(i<=j){
            if(f){
                if(m[s[i]]>1){
                    m[s[i]]--;
                    s[i]='0';
                    i++;
                    f=0;
                }
                else{
                    i++;
                }
            }
            else{
                if(m[s[j]]>1){
                    m[s[j]]--;
                    s[j]='0';
                    j--;
                    f=1;
                }
                else{
                    j--;
                }
            }
        }
        string ans;
        for(auto it:s){
            if(it!='0'){
                ans+=it;
            }
        }
        if(f==0){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends