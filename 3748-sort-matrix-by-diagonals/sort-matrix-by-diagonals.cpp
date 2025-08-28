class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int n=g.size();
        for(int j=n-1;j>0;j--){
            int i=0,x=j;
            vector<int>v;
            while(i<n&&x<n){
             v.push_back(g[i][x]);
             i++;
             x++;
            }
            sort(v.begin(),v.end());

         i=0,x=j;
         int k=0;
      //   cout<<"hi"<<endl;
         while(i<n&&x<n){
          //  cout<<v[k]<<endl;
            g[i][x]=v[k++];
            i++;
            x++;
         }
        }
         for(int j=0;j<n;j++){
            vector<int>v;
            int i=j,x=0;
            while(i<n&&x<n){
             v.push_back(g[i][x]);
             i++;
             x++;
            }
            sort(v.begin(),v.end(),greater<int>());
         i=j,x=0;
         int k=0;
         while(i<n&&x<n){
           cout<<v[k]<<endl;
            g[i][x]=v[k++];
            i++;
            x++;
         }
        }
        return g;
    }
};