class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<=n-k;i++){
            int x=0,y=k-1;
            vector<int>res;
            while(x<=m-k){
                 int ans=INT_MAX;
                  vector<int>v;
                 for(int j=i;j<i+k;j++ ){
                    for(int l=x;l<=y;l++){
                        v.push_back(g[j][l]);
                                            }
                 }
                 sort(v.begin(),v.end());
                 for(int i=1;i<v.size();i++){
                  if(v[i]!=v[i-1]) ans=min(ans,abs(v[i]-v[i-1]));
                 }
                 
                 if(ans!=INT_MAX) res.push_back(ans);
                 else res.push_back(0);
                  x++;
                  y++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};