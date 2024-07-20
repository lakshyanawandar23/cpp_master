class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n=r.size(),m=c.size();
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                v[i][j]=min(r[i],c[j]);
                r[i]-=v[i][j];
                c[j]-=v[i][j];
            }
        }
        return v;
    }
};