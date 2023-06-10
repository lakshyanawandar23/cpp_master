class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                set<int>r,l;
                int x=i-1,y=j-1;
                while(x>=0&&y>=0){
                    l.insert(g[x][y]);
                    x=x-1;
                    y=y-1;
                }
                x=i+1;
                y=j+1;
                 while(x<n&&y<m){
                    r.insert(g[x][y]);
                    x=x+1;
                    y=y+1;
                }
                int a=r.size(),b=l.size();
                ans[i][j]=abs(a-b);
            }
        }
        return ans;
    }
};