class Solution {
public:
   void dfs(int ver,vector<int>&v,int comp,vector<vector<int>>&adj,unordered_map<int,set<int>>&mp){
            v[ver]=comp;
            mp[comp].insert(ver);
            for(auto it:adj[ver]){
                if(v[it]==0){
                    dfs(it,v,comp,adj,mp);
                }
            }
   }
    vector<int> processQueries(int c, vector<vector<int>>& s, vector<vector<int>>& q) {
        vector<int>v(c+1,0);
        unordered_map<int,set<int>>mp;
        vector<vector<int>>adj(c+1);
        for(auto it:s){
            adj[it[0]].push_back(it[1]);
              adj[it[1]].push_back(it[0]);
        }
        int comp=1;
        for(int i=1;i<=c;i++){
            if(v[i]==0){
                dfs(i,v,comp,adj,mp);
                comp++;
            }
        }
        vector<int>ans;
        for(auto it:q){
             int t=it[0];
             int ver=it[1];
             int compo=v[ver];   //which componenent it is
             auto &smallest=mp[compo];  //smallest id in thaat grid
             if(t==2){
               // cout<<t<<" "<<ver<<endl;
                smallest.erase(ver);
             }
          else   if(smallest.find(ver)!=smallest.end()){
          //  cout<<ver<<endl;
                        ans.push_back(ver);
             }
             else {
                if(!smallest.empty()){
                auto val=smallest.begin();
             //   cout<<*val<<endl;
                ans.push_back(*val);
                }
                else {
                    ans.push_back(-1);
                }
             }
        }
        return ans;
    }
};