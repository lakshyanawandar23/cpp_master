class Solution {
public:
    void solve(int s,vector<vector<int>>&g,vector<vector<int>>&ans,vector<int>v){
        if(s==g.size()-1){
            v.push_back(s);
            ans.push_back(v);
            return ;
        }
        v.push_back(s);
        for(auto it:g[s]){
            solve(it,g,ans,v);
        }
        v.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,g,ans,v);
        return ans;
    }
};