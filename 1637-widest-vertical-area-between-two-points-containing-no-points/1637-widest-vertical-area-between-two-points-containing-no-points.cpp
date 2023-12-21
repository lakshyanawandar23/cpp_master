class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        int n=p.size(),ans=0;
        sort(p.begin(),p.end());
        for(int i=1;i<n;i++){
            ans=max(ans,abs(p[i][0]-p[i-1][0]));
        }
        return ans;
    }
};