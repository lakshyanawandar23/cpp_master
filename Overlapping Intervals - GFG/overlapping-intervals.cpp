//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& s) {
         // Code here
         vector<vector<int>>v;
          sort(s.begin(),s.end());
         int st=s[0][0];
         int e=s[0][1];
            vector<int>t;
         for(int i=1;i<s.size();i++){
             if(e>=s[i][0]){
                 e=max(e,s[i][1]);
             }
             else{
                 t.push_back(st);
                 t.push_back(e);
                 v.push_back(t);
                 t.clear();
                 st=s[i][0];
                 e=s[i][1];
             }
         }
          t.push_back(st);
                 t.push_back(e);
                 v.push_back(t);
                 return v;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends