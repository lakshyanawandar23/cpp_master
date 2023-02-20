//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int n){
        // code here 
        long long int cnt=0,m=1000000007;
        if(n<2){
            return 0;
            
        }
        int i=2;
        while(i<=n){
            cnt=(cnt*3)%m;
            if(i%2!=0){
                cnt=cnt-3;
            }
            else{
                cnt+=3;
            }
        i++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends