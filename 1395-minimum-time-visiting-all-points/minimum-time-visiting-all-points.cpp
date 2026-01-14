class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans=0;
        for(int i=1;i<p.size();i++){
            int x=abs(p[i][0]-p[i-1][0]);
            int y=abs(p[i][1]-p[i-1][1]);
            ans+=max(x,y);
        }
        return ans;
    }
};