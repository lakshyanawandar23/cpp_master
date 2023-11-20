class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int p=0,glass=0,m=0,pdx=0,mdx=0,glassdx=0,n=g.size();
        vector<int>pre(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
            if(g[i][j]=='M'){
                mdx=i;
                m++;
            }
            else if(g[i][j]=='P'){
                pdx=i;
                p++;
            }
            else if(g[i][j]=='G'){
                glassdx=i;
                glass++;
            }
            }
            if(i>0){
            pre[i]=pre[i-1]+t[i-1];
            }
            
        }
      //  cout<<pre[glassdx]<<endl;
        return ((pre[pdx]+p)+(pre[glassdx]+glass)+(pre[mdx]+m));
    }
};