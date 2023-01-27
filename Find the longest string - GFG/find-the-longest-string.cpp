//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &w)
    {
        
        // code here
        sort(w.begin(),w.end());
        unordered_map<string,int>m;
        for(auto it:w){
            m[it]++;
        }
        string ans="";
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i].size();j++){
                
                string r=w[i].substr(0,j+1);
                if(m.find(r)!=m.end()){
                    if(ans.size()<r.size()&&ans<r){
                        ans=r;
                    }
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends