class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
         vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double>prob(n,0.0);
        prob[start]=1;
        //maxHeap of prob and node
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int next=it.first;
                double next_prob=it.second;
                if(prob[node]*next_prob>prob[next])
                {
                    prob[next]=prob[node]*next_prob;
                    pq.push({prob[next],next});
                }
            }
        }
        return prob[end];

    }
};