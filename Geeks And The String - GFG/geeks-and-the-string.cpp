//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char>p;
        for(int i=0;i<s.size();i++){
            if(p.size()>0&&p.top()==s[i]){
            while(!p.empty()&&p.top()==s[i]){
                p.pop();
            }
        }
        else{
            p.push(s[i]);
        }
        }
        string ans;
        while(!p.empty()){
            ans=p.top()+ans;
            p.pop();
        }
        if(ans.size()>0){
        return ans;
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends