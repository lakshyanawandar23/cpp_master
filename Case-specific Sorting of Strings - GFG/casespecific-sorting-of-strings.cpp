//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        string l,u;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                l+=s[i];
            }
            else{
                u+=s[i];
            }
        }
        sort(l.begin(),l.end());
        sort(u.begin(),u.end());
        int k=0,j=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                s[i]=l[k];
                k++;
            }
            else{
                s[i]=u[j];
                j++;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends