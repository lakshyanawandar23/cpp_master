class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1&&i>0){
                    mat[i][j]=mat[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end(),greater<int>());
            for(int j=0;j<mat[i].size();j++){
                ans=max(ans,(mat[i][j]*(j+1)));
            }
        }
        return ans;
    }
};