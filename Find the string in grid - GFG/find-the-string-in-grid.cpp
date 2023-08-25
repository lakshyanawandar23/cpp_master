//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};
  bool solve(vector<vector<char>>&g,string &w,int x,int y){
      for(int p=0;p<8;p++){
          int i=dx[p]+x;
          int j=dy[p]+y;
          int k=1;
          if(i>=0&&j>=0&i<g.size()&&j<g[0].size()){
              while(i>=0&&j>=0&i<g.size()&&j<g[0].size()&&k<w.size()){
              if(g[i][j]==w[k]){
                 i=dx[p]+i;
                 j=dy[p]+j;
                 k++;
              }
              else{
                  break;
              }
          }
           if(k==w.size()) return true;
      }
  }
    return false;
  }
	vector<vector<int>>searchWord(vector<vector<char>>g, string word){
	    // Code here
	    vector<vector<int>>ans;
	    for(int i=0;i<g.size();i++){
	        for(int j=0;j<g[0].size();j++){
	            if(g[i][j]==word[0]){
	                if(solve(g,word,i,j)){
	                    vector<int>v;
	                   // cout<<i<<""<<j;
	                    v.push_back(i);
	                    v.push_back(j);
	                    ans.push_back(v);
	                }
	            }
	        }
	    }
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends