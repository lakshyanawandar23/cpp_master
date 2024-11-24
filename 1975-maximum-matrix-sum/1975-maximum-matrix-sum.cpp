class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int mini=1e9;
        long long int ans=0,cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]<0) {cnt++;}
                mini=min(mini,abs(mat[i][j]));
              ans+=abs(mat[i][j]);
            }
        }
        if(cnt%2!=0) {
            ans-=(mini*2);
        }
        return ans;
    }
};