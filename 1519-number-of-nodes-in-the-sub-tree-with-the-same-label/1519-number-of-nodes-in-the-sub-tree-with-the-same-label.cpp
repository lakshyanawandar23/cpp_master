class Solution {
public:
    vector<int> solve(vector<int>&ans,vector<int>adj[],string &l,int src,int parent){
        vector<int>cnt(26,0);
        for(auto val:adj[src]){
            if(val!=parent){
         auto temp=    solve(ans,adj,l,val,src);
                for(int i=0;i<26;i++){
                    cnt[i]+=temp[i];
                }
        }
        }
            int ch=l[src]-'a';
            cnt[ch]++;
           ans[src]=cnt[ch];
    return cnt;
    
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string l) {
        vector<int>adj[n];
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        vector<int>ans(n,1);
        solve(ans,adj,l,0,-1);
        return ans;
    }
};