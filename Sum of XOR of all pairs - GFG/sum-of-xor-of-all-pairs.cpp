//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
       long long int ret = 0;
        vector<int> bits(32, 0);
        for(int i = 0; i < n; i++) {
            for(int b = 0; b < 32; b++) {
                if(arr[i] & (1 << b)) {
                    // then, add unset bits to answer
                    ret += (i - bits[b]) * 1ll * (1 << b);
                    bits[b]++;
                }
                else {
                    // then, add set bits to answer
                    ret += bits[b] * 1ll * (1 << b);
                }
            }
        }
        return ret;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends