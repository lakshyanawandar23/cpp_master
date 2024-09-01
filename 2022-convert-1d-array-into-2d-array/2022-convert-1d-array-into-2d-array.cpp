class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& v, int m, int n) {
        vector<vector<int>>mat(m,vector<int>(n));
        int i=0,j=0,k=0;
         if((n*m)>v.size()||(n*m)<v.size()) return {};
        for( k=0;k<v.size()&&i<m;){
            j=0;
            while(j<n){
                mat[i][j++]=v[k];
                k++;
            }
            i++;
        }
       
        return mat;
    }
};