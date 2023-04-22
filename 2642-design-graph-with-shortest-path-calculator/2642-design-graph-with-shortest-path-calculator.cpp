typedef  pair<int,int> pi;
#define pq priority_queue<pi,vector<pi>,greater<pi>>
class Graph {
public:
    vector<vector<pair<int,long long int>>>adj;
    int m;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
   for( auto &e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
         adj[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int st, int end) {
        vector<int>vis(adj.size(),INT_MAX);
      pq minH;
     minH.push({0,st});
     vis[st]=0;
     while(!minH.empty() && minH.top().second!=end)
     {
          auto [currD,currN]=minH.top();
         minH.pop();
         if(currD>vis[currN]) 
         continue;
         for(auto &[adjN,adjD]:adj[currN])
         {
             if(adjD+currD<vis[adjN])
             {
                 vis[adjN]=adjD+currD;
                   minH.push({vis[adjN],adjN});
             }
             
         }
     }
     return vis[end]!=INT_MAX ? vis[end] :-1; 

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */