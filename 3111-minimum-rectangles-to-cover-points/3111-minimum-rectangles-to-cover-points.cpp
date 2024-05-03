class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {
        int n=p.size();
        sort(p.begin(),p.end());
        int  cnt=1,prev=p[0][0];
        for(int i=1;i<n;i++){
            if((p[i][0]-prev)>w){
                cnt++;
                prev=p[i][0];
            }
        }
        return cnt;
    }
};