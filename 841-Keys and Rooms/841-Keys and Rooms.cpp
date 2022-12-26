class Solution {
public:
    vector<int> arr[1001];
    bool vis[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                arr[i].push_back(rooms[i][j]);
            }
        }
        dfs(0);
        for(int i=0;i<rooms.size();i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
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
