class Solution {
public:
    int cnt;
  long long  int  solve(int src,vector<int>adj[],int &k,vector<int>&val,vector<int>&vis){
        if(vis[src]){
          return  0;
        }
        vis[src]=1;
       long long int sum=val[src];
        for(auto it:adj[src]){
            sum+=solve(it,adj,k,val,vis);
        }
        if((sum)%k==0){
          //  cout<<sum<<endl;
            cnt++;
            return 0;
        }
            return sum;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& val, int k) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
           adj[e[i][1]].push_back(e[i][0]);
        }
         cnt=0;
        solve(0,adj,k,val,vis);
        return cnt;
    }
};