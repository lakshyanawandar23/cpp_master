//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int l=0,r=m-1,up=0,down=n-1,cnt=0;
 		//vector<int>v;
 		while(l<=r&&up<=down){
 		    for(int i=l;i<=r;i++){
 		        cnt++;
 		        if(cnt==k){
 		        return (a[up][i]);
 		    }
 		    }
 		    up++;
 		    for(int i=up;i<=down;i++){
 		       cnt++;
 		        if(cnt==k){
 		        return (a[i][r]);
 		    }
 		    }
 		    r--;
 		    for(int i=r;i>=l;i--){
 		        cnt++;
 		        if(cnt==k){
 		        return (a[down][i]);
 		    }
 		    }
 		    down--;
 		    for(int i=down;i>=up;i--){
 		        cnt++;
 		        if(cnt==k){
 		        return (a[i][l]);
 		    }
 		    }
 		    l++;
 		}
 		return 0;
    }
};
//TC O(N*M);
//SCO(N*M);




//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends