//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long int>ans(n,0);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
           long long int sum=0,cnt=0;
        ans[v[0].second]=0;
        for(int i=1;i<n;i++){
            sum+=v[i-1].first;
            if(v[i].first!=v[i-1].first){
                ans[v[i].second]=sum;
                cnt=0;
            }
            else{
                cnt++;
                ans[v[i].second]=(sum-cnt*v[i].first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends