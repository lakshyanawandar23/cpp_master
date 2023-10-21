//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    // code here
	    vector<int>dist(v,1e9);
	    queue<int>q;
	    q.push(0);
	    dist[0]=0;
	    while(!q.empty()){
	        auto p=q.front();
	        q.pop();
	        if(p==x){
	            return dist[p];
	        }
	        for(auto val:adj[p]){
	            if(dist[val]>1+dist[p]){
	                dist[val]=1+dist[p];
	                q.push(val);
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends