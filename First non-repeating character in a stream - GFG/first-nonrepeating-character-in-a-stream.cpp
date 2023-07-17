//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    vector<char>p;
		    vector<int>v(26,0);
		    string ans;
		    int k=0;
		    for(int i=0;i<s.size();i++){
		        v[s[i]-'a']++;
		        if(v[s[i]-'a']==1){
		            p.push_back(s[i]);
		        }
		        char c='#';
		        while(k<p.size()&&v[p[k]-'a']!=1){
		            k++;
		        }
		        if(k<p.size()&&v[p[k]-'a']==1){
		            c=p[k];
		        }
		        ans+=c;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends