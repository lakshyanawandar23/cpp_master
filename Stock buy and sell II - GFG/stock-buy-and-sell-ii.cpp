//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int solve(int n,vector<int>p,vector<vector<int>>&dp,int buy,int i){
      if(i==n){
          return 0;
      }
      if(dp[i][buy]!=-1){
          return dp[i][buy];
      }
      int profit=0;
      if(!(buy)){
          profit+=max(-p[i]+solve(n,p,dp,1,i+1),0+solve(n,p,dp,0,i+1));
      }
      else{
          profit+=max(p[i]+solve(n,p,dp,0,i+1),0+solve(n,p,dp,1,i+1));
      }
      return dp[i][buy]=profit;
  }
    int stockBuyAndSell(int n, vector<int> &p) {
        // code here
       // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        //return solve(n,p,dp,0,0);
        int profit=0;
        for(int i=1;i<n;i++){
            if(p[i]>=p[i-1]){
                profit+=(p[i]-p[i-1]);
            }
        }
        return profit;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends