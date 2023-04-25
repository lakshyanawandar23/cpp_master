//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        stack<int>s;
        vector<int>l,r;
        for(int i=0;i<arr.size();i++){
            while(!s.empty()&&arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                l.push_back(-1);
            }
            else{
                l.push_back(s.top());
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
          for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty()&&arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                r.push_back(-1);
            }
            else{
                r.push_back(s.top());
            }
            s.push(i);
        }
        reverse(r.begin(),r.end());
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
           // cout<<l[i]<<" "<<r[i]<<endl;
            if(l[i]==-1&&r[i]==-1){
                ans[i]=-1;
            }
            else if(l[i]==-1){
                ans[i]=r[i];
            }
            else if(r[i]==-1){
                ans[i]=l[i];
            }
            else {
               if( abs(i-l[i]) < abs(i-r[i]) )
                    ans[i]=l[i];
                else if( abs(i-l[i]) > abs(i-r[i]) )
                    ans[i]=r[i];  
                else if(arr[l[i]] > arr[r[i]])
                    ans[i]=r[i];  
                else   
                    ans[i]=l[i]; 
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends