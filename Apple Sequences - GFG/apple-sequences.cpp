//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here
        int i=0,cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]=='A'){
                cnt=max(cnt,j-i+1);
            }
            else{
                if(m>0){
                    cnt=max(j-i+1,cnt);
                    m--;
                }
                else{
                    while(arr[i]!='O'){
                        i++;
                    }
                    i++;
                    m++;
                    cnt=max(j-i+1,cnt);
                    m--;
                }
            }
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends