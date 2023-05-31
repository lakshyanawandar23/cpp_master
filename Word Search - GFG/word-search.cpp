//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool solve(int i,int j,vector<vector<char>>&b,string &w,vector<vector<int>>&vis,int k,int &n,int &m){
    if(k==w.size()) {
        return true;
    }
    if(i<0||j<0||i==n||j==m||vis[i][j]==1||b[i][j]!=w[k]){
        return false;
    }
    vis[i][j]=1;
    bool a=solve(i+1,j,b,w,vis,k+1,n,m);
     bool e=solve(i-1,j,b,w,vis,k+1,n,m);
      bool c=solve(i,j-1,b,w,vis,k+1,n,m);
       bool d=solve(i,j+1,b,w,vis,k+1,n,m);
       return a||e||c||d;
    }

    bool isWordExist(vector<vector<char>>& b, string w) {
        // Code here
        int n=b.size(),m=b[0].size();
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]==w[0]){
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    if(solve(i,j,b,w,vis,0,n,m))  return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends