class Solution {
public:
    bool solve(vector<vector<char>>&b,string &w,vector<vector<int>>&vis,int i,int j,int &n,int &m,int k){
       if(k==w.size()) return true;
        if(i>=n||j>=m||i<0||j<0||vis[i][j]==1) return false;
        bool ans=false;
        if(w[k]==b[i][j]&&vis[i][j]==0){
            vis[i][j]=1;
           ans= solve(b,w,vis,i+1,j,n,m,k+1)||solve(b,w,vis,i-1,j,n,m,k+1)||solve(b,w,vis,i,j+1,n,m,k+1)||solve(b,w,vis,i,j-1,n,m,k+1);
        }
        vis[i][j]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size(),m=b[0].size();
        if(w.size()==1&&n==1&&m==1&&b[0][0]==w[0]) return true;
        for(int i=0;i<b.size();i++){
          for(int j=0;j<b[0].size();j++){
              vector<vector<int>>vis(n,vector<int>(m,0));
              if(b[i][j]==w[0]){
              if(solve(b,w,vis,i,j,n,m,0)){
                  return true;
              }
              }
          }
        }
        return false;
    }
};