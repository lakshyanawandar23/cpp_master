class Solution {
public:
  int dfs(int i,vector<int>&vis,vector<int>&num){
  if(vis[i]==1) return 0;
    vis[i]=1;
     int pick=0;
    return  pick=1+dfs(num[i],vis,num);
  }
    int arrayNesting(vector<int>& num) {
        int n=num.size(),cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               cnt=max(cnt, dfs(i,vis,num));
            }
        }
        return cnt;
    }
};