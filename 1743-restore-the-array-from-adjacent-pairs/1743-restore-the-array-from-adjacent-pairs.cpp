class Solution {
public:
    void solve(set<int>&s,vector<int>&v,map<int,vector<int>>&m,int &st){
       s.insert(st);
      v.push_back(st);
        for(auto it:m[st]){
           // cout<<it<<endl;
            if(s.find(it)==s.end()){
                solve(s,v,m,it);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adj) {
        map<int,vector<int>>m;
        for(int i=0;i<adj.size();i++){
            m[adj[i][0]].push_back(adj[i][1]);
            m[adj[i][1]].push_back(adj[i][0]);
        }
      
        int st=0;
        for(auto it:m){
         if(it.second.size()==1){
             st=it.first;
             break;
         }
        }
        set<int>s;
      vector<int>v;
        solve(s,v,m,st);
        return v;
    }
};