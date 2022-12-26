class Solution {
public:
    vector<int> arr[300001];
    bool vis[300001];
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        if(edges.size()==0){
            return true;
        }
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            arr[a].push_back(b) , arr[b].push_back(a);
        }
        dfs(src);
        return vis[dst];
    }
    void dfs(int node){
        vis[node]=true;
        for(auto child:arr[node]){
            if(!vis[child]){
                dfs(child);
            }
        }
    }
};
