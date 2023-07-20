//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       vector<int>v(26,0);
       char ans='$';
       vector<char>res;
       for(int i=0;i<s.size();i++){
           v[s[i]-'a']++;
           if(v[s[i]-'a']==1){
               res.push_back(s[i]);
           }
       }
       for(auto it:res){
           if(v[it-'a']==1){
               return it;
           }
       }
       return ans;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends