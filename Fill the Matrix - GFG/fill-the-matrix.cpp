//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    int minIteration(int n, int m, int x, int y){    
        // code here
        queue<pair<int,int>>q;
        q.push({x-1,y-1});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[x-1][y-1]=1;
        int cnt=0;
        while(!q.empty()){
            int k=q.size();
            cnt++;
            while(k--){
                auto p=q.front();
                q.pop();
                for(int k=0;k<4;k++ ){
                    int i=p.first+dx[k];
                    int j=p.second+dy[k];
                    if(i>=0&&j>=0&&i<n&&j<m&&vis[i][j]==0){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }
        return cnt-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends