//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int> > findDistance(vector<vector<char> >& mat, int n, int m) 
    { 
        // Your code goes here
        vector<vector<int>>dis(n,vector<int>(m));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='W'){
                    dis[i][j]=-1;
                }
                else if(mat[i][j]=='O'){
                    dis[i][j]=1e9;
                }
                else{
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=dx[k]+p.first;
                int y=dy[k]+p.second;
                if(x>=0&&y>=0&&x<n&&y<m&&dis[x][y]>dis[p.first][p.second]){
                    dis[x][y]=1+dis[p.first][p.second];
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dis[i][j]==1e9){
                    dis[i][j]=-1;
                }
            }
        }
        return dis;
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends