//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int rem=0;
       for(int i=0;i<x.size();i++){
         //  cout<<rem<<endl;
           rem=(rem*10)+(x[i]-'0');
           if(rem>=11){
               int s=(rem%11);
               rem=s;
           }
       }
       return rem;
    
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends