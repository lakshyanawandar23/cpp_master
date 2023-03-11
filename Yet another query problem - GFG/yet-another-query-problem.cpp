//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &q) {
        // code here
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(a[i]==a[j]){
                    cnt++;
                }
            }
            m[i]=cnt;
        }
        vector<int>ans;
        for(auto it:q){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int cnt=0;
            for(int i=l;i<=r;i++ ){
                if(m[i]==k){
                    cnt++;
                }
            }
           ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends