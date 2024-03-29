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
    long long solve(int n, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<int>a,b,c,d;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                a.push_back(arr[i]);
            }
            else{
                b.push_back(arr[i]);
            }
        }
    for(int i=0;i<brr.size();i++){
            if(brr[i]%2==0){
                c.push_back(brr[i]);
            }
            else{
                d.push_back(brr[i]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
    long long  int inc=0,dec=0;
    if(a.size()!=c.size()) return -1;
    if(b.size()!=d.size()) return -1;
        for(int i=0;i<a.size();i++){
            if(c[i]>=a[i]){
                inc+=(c[i]-a[i]);
            }
            else{
                dec+=(c[i]-a[i]);
            }
        }
        for(int i=0;i<b.size();i++){
            if(d[i]>=b[i]){
                inc+=(d[i]-b[i]);
            }
            else{
                dec+=(d[i]-b[i]);
            }
        }
        if(inc+dec==0){
            return inc/2;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends