class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<int>a(n);
        vector<int>b(n);
        vector<int>c(m);
        vector<int>d(m);
        for(int i=0;i<n;i++){
            int x=0,y=0;
        for(int j=0;j<m;j++){
            if(g[i][j]==0){
                x++;
            }
            else{
                y++;
            }
        }
            a[i]=x;
            b[i]=y;
        }
         for(int i=0;i<m;i++){
            int x=0,y=0;
        for(int j=0;j<n;j++){
            if(g[j][i]==0){
                x++;
            }
            else{
                y++;
            }
        }
            c[i]=x;
            d[i]=y;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              //  cout<<c[j]<<" "<<d[j]<<endl;
                g[i][j]=b[i]+d[j]-a[i]-c[j];
            }
        }
        return g;
    }
};