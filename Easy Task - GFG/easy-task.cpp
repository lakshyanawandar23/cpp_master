//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int m,vector<vector<string>> &q){
        // Code here
        vector<char>ans;
        for(int i=0;i<m;i++){
            auto type=q[i][0];
            if(type=="1"){
                int idx=stoi(q[i][1]);
              char c=q[i][2][0];
                s[idx]=c;
            }
            else{
                vector<int>v(26,0);
                int l=stoi(q[i][1]);
                int r=stoi(q[i][2]);
                int k=stoi(q[i][3]);
                for(int i=l;i<=r;i++){
                    v[s[i]-'a']++;
                }
                int sum=0;
                for(int i=25;i>=0;i--){
                    sum+=(v[i]);
                    if(sum>=k){
                        ans.push_back('a'+i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends