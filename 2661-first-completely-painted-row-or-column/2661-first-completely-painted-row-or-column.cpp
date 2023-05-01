class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int ans,n=mat.size(),m=mat[0].size();
        unordered_map<int,int>r,c;
        vector<pair<int,int>>v(m*n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            auto p=v[arr[i]];
            r[p.first]++;
            if(r[p.first]==m){
                return i;
            }
            c[p.second]++;
            if(c[p.second]==n){
                return i;
            }
        }
        return -1;
    }
};