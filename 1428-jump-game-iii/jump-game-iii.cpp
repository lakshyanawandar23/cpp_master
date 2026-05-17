class Solution {
public:
  bool dp[10001];
   bool solve(int i,vector<int>&vis,vector<int>&arr,int &n){
      if(i>=n ||i<0) return false;
      if(arr[i]==0) return true;
       if(vis[i]==1) return false;;
       vis[i]=1;
       if(solve(i+arr[i],vis,arr,n)) return true;
       if(solve(i-arr[i],vis,arr,n)) return true;
       return false;
   }
    bool canReach(vector<int>& arr, int st) {
        int n=arr.size();
        vector<int>vis(n+1,0);
       memset(dp,-1,sizeof(dp));
       return  solve(st,vis,arr,n);
    }
};