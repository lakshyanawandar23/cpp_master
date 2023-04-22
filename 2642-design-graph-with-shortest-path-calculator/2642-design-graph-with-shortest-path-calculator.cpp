class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    int m;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        m=n;
      for( auto &e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
         adj[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int n1, int n2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>dis(m,INT_MAX);
        dis[n1]=0;
        q.push({0,n1});
        while(!q.empty()){
            auto p=q.top();
            q.pop();
        if(p.first<dis[p.second]){
            continue;
        }
            for(auto it:adj[p.second]){
                int s=p.first+it.second;
                if(dis[it.first]>s){
                    dis[it.first]=s;
                q.push({s,it.first});
                }
            }
        }
        return dis[n2]==INT_MAX?-1:dis[n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */